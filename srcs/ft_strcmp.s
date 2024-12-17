global ft_strcmp
section .text

; rdi = const char* = s1
; rsi = const char* = s2

ft_strcmp:
    xor rax, rax

loop:
    mov cl, BYTE[rdi + rax]
    mov dl, BYTE[rsi + rax]
    cmp cl, 0
    jz return
    cmp dl, 0
    jz return
    cmp cl, dl
    jnz return
    inc rax
    jmp loop

return:
    sub cl, dl
    movsx rax, cl
    ret