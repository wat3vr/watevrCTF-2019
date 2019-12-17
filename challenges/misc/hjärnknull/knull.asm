; [x] = global data, sätts till en ledig data slot
; (x) = lokal data, sätts till en ledig data slot inom macro
; .x = label, motsvarar en address

#macro clear a
    eller (1) a
    inte a
    eller a (1)
    inte a
#endmacro

#macro mov a b
    clear a
    eller a b
#endmacro

#macro och a b
    inte a
    mov (1) b
    inte (1)
    eller a (1)
    inte a
#endmacro

#macro jmp a
    testa [zero] [zero] a
#endmacro

#macro xor a b
    mov (1) a
    inte (1)
    mov (2) a
    och (2) b
    eller (1) (2)
    inte (1)

    mov (3) b
    inte (3)
    mov (4) a
    och (4) b
    eller (3) (4)
    inte (3)
    eller (1) (3)

    mov a (1)
#endmacro

#macro add a b
    mov (b) b
.loop:
    testa (b) [zero] .end
    mov (1) a
    xor a (b)
    och (b) (1)
    vsh (b) [one]
    jmp .loop
.end:
#endmacro

#macro sub a b
    mov (b) b
.loop:
    testa (b) [zero] .end
    mov (1) a
    inte (1)
    och (1) (b)
    xor a (b)
    mov (b) (1)
    vsh (b) [one]
    jmp .loop
.end:
#endmacro

#macro mul a b
    mov (ans) [zero]
    mov (count) [zero]
    mov (m) b
.loop:
    testa (m) [zero] .end
    mov (1) (m)
    och (1) [one]
    testa (1) [zero] .skip
    mov (1) a
    vsh (1) (count)
    add (ans) (1)
.skip:
    add (count) [one]
    hsh (m) [one]
    jmp .loop
.end:
    mov a (ans)
#endmacro

.start:
    ; Init scalars
    clear [zero]
    vsh [two] [one]

.take_input:
    in [op]
    in [a]
    in [b]
    testa [op] [zero] .add
    testa [op] [one] .sub
    testa [op] [two] .mul
.add:
    add [a] [b]
    jmp .print_result
.sub:
    sub [a] [b]
    jmp .print_result
.mul:
    mul [a] [b]
    jmp .print_result
.print_result:
    ut [a]
    jmp .take_input
.end:
