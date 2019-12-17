const fs = require("fs");
const util = require("util");

function assemble(input) {
	input = input.replace(/;[^\n]*/g, "");

	input = input.split(/\r?\n/);

	let program = [];

	let macros = {};
	let macro = null;

	let dataIndex = 0;
	let globals = {};

	function expandMacros(code) {
		for (let i=0; i<code.length; i++) {
			if (code[i].type !== "instruction" || !(code[i].op in macros)) continue;

			let macroCode = [];
			let macro = macros[code[i].op];
			for (let j=0; j<macro.code.length; j++) {
				let entry = macro.code[j];
				if (entry.type === "instruction") {
					let args = [];
					for (let k=0; k<entry.args.length; k++) {
						let arg = entry.args[k];
						if (macro.args.includes(arg)) {
							arg = code[i].args[macro.args.indexOf(arg)];
						} else if (typeof arg === "string" && arg.startsWith(".")) {
							arg = "." + i + "#" + arg;
						}
						args.push(arg);
					}
					macroCode.push({
						type: "instruction",
						op: entry.op,
						args: args
					});
				} else {
					macroCode.push({
						type: "label",
						name: "." + i + "#" + entry.name
					});
				}
			}

			code.splice(i, 1, ...macroCode);
		}

		let variables = {};
		for (let i=0; i<code.length; i++) {
			if (code[i].type !== "instruction") continue;

			for (let j=0; j<code[i].args.length; j++) {
				let arg = code[i].args[j];
				if (/^\[.+\]$/.test(arg)) {
					if (!(arg in globals)) {
						globals[arg] = dataIndex++;
					}
					arg = globals[arg];
				} else if (/^\(.+\)$/.test(arg)) {
					if (!(arg in variables)) {
						variables[arg] = dataIndex++;
					}
					arg = variables[arg];
				}
				code[i].args[j] = arg;
			}
		}
	}

	for (let i=0; i<input.length; i++) {
		let line = input[i].split(/[ \t]+/).filter(a => a !== "");
		if (line.length === 0) continue;
		if (line[0] === "#macro") {
			let name = line[1];
			let args = line.slice(2);
			macro = {
				name: name,
				args: args,
				code: []
			};
		} else if (line[0] === "#endmacro") {
			expandMacros(macro.code);
			macros[macro.name] = macro;
			macro = null;
		} else if (/^.+\:$/.test(line[0])) {
			let label = {type: "label", name: line[0].slice(0, -1)};
			if (macro === null) {
				program.push(label);
			} else {
				macro.code.push(label);
			}
		} else {
			let instruction = {type: "instruction", op: line[0], args: line.slice(1)};
			if (macro === null) {
				program.push(instruction);
			} else {
				macro.code.push(instruction);
			}
		}
	}

	expandMacros(program);

	let labels = {};
	let ip = 0;
	for (let i=0; i<program.length; i++) {
		if (program[i].type === "instruction") {
			ip++;
		} else if (program[i].type === "label") {
			labels[program[i].name] = ip;
		}
	}
	for (let i=0; i<program.length; i++) {
		if (program[i].type !== "instruction") continue;

		let args = [];
		for (let j=0; j<program[i].args.length; j++) {
			let arg = program[i].args[j];
			if (arg in labels) {
				arg = labels[arg];
			}
			args.push(arg);
		}
		program[i].args = args;
	}

	let out = [];
	for (let i=0; i<program.length; i++) {
		if (program[i].type !== "instruction") continue;

		out.push(program[i].op + " " + program[i].args.join(" "));
	}
	out.push("slut");
	out = out.join("\n");

	//console.log(program);
	console.log(out);
}

assemble(fs.readFileSync("knull.asm", "utf-8"));
