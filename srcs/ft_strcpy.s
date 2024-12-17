global ft_strcpy
section .text

; rdi = char* = dest
; rsi = const char* = src

ft_strcpy:
    xor rax, rax

loop:
    mov dl, [rsi + rax]
    mov [rdi + rax], dl
    cmp dl, 0
    jz return
    inc rax
    jmp loop

return:
    mov byte[rdi + rax], 0
    mov rax, rdi
    ret