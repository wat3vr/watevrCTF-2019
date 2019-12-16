import ast

whitelist = [
    ast.Module,
    ast.Expr,

    ast.Num,

    ast.UnaryOp,

        ast.UAdd,
        ast.USub,
        ast.Not,
        ast.Invert,

    ast.BinOp,

        ast.Add,
        ast.Sub,
        ast.Mult,
        ast.Div,
        ast.FloorDiv,
        ast.Mod,
        ast.Pow,
        ast.LShift,
        ast.RShift,
        ast.BitOr,
        ast.BitXor,
        ast.BitAnd,
        ast.MatMult,

    ast.BoolOp,

        ast.And,
        ast.Or,
    
    ast.Compare,

        ast.Eq,
        ast.NotEq,
        ast.Lt,
        ast.LtE,
        ast.Gt,
        ast.GtE,
        ast.Is,
        ast.IsNot,
        ast.In,
        ast.NotIn,

]

operators = {
    
        ast.UAdd: "+",
        ast.USub: "-",
        ast.Not: "not ",
        ast.Invert: "~",

        ast.Add: " + ",
        ast.Sub: " - ",
        ast.Mult: " * ",
        ast.Div: " / ",
        ast.FloorDiv: " // ",
        ast.Mod: " * ",
        ast.Pow: " ** ",
        ast.LShift: " << ",
        ast.RShift: " >> ",
        ast.BitOr: " | ",
        ast.BitXor: " ^ ",
        ast.BitAnd: " & ",
        ast.MatMult: " @ ",

        ast.And: " and ",
        ast.Or: " or ",

        ast.Eq: " == ",
        ast.NotEq: " != ",
        ast.Lt: " < ",
        ast.LtE: " <= ",
        ast.Gt: " > ",
        ast.GtE: " >= ",
        ast.Is: " is ",
        ast.IsNot: " is not ",
        ast.In: " in ",
        ast.NotIn: " not in ",
}

def format_ast(node):

    if isinstance(node, ast.Expression):
        code = format_ast(node.body)
        if code[0] == "(" and code[-1] == ")":
            code = code[1:-1]
        return code
    if isinstance(node, ast.Num):
        return str(node.n)
    if isinstance(node, ast.UnaryOp):
        return operators[node.op.__class__] + format_ast(node.operand)
    if isinstance(node, ast.BinOp):
        return (
            "("
            + format_ast(node.left)
            + operators[node.op.__class__]
            + format_ast(node.right)
            + ")"
        )
    if isinstance(node, ast.BoolOp):
        return (
            "("
            + operators[node.op.__class__].join(
                [format_ast(value) for value in node.values]
            )
            + ")"
        )
    if isinstance(node, ast.Compare):
        return (
            "("
            + format_ast(node.left)
            + "".join(
                [
                    operators[node.ops[i].__class__] + format_ast(node.comparators[i])
                    for i in range(len(node.ops))
                ]
            )
            + ")"
        )


def check_ast(code_ast):
    for _, nodes in ast.iter_fields(code_ast):
        if type(nodes) != list:
            nodes = [nodes]
        for node in nodes:
            if node.__class__ not in whitelist:
                return False, node.__class__.__name__
            if not node.__class__ == ast.Num:
                result = check_ast(node)
                if not result[0]:
                    return result

    return True, None


def validate(code):
    if len(code) > 512:
        return False, "That's a bit too long m8"

    if "__" in code:
        return False, "I dont like that long floor m8"
    if "[" in code or "]" in code:
        return False, "I dont like that 3/4 of a rectangle m8"
    if '"' in code:
        return False, "I dont like those two small vertical lines m8"
    if "'" in code:
        return False, "I dont like that small vertical line m8"

    try:
        code_ast = ast.parse(code, mode="eval")
    except SyntaxError:
        return False, "Check your syntax m8"
    except ValueError:
        return False, "Handle your null bytes m8"

    result = check_ast(code_ast)
    if result[0]:
        return True, format_ast(code_ast)

    return False, f"You cant use ast.{result[1]} m8"
