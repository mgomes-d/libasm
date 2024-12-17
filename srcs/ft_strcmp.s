global ft_strcmp
section .text

; rdi = const char* = s1
; rsi = const char* = s2

ft_strcmp:
    xor rax, rax
    xor rcx, rcx

loop:
    cmp BYTE[rdi + rcx], 0
    jz return
    cmp BYTE[rsi + rcx], 0
    jz return
    mov dl, BYTE[rsi + rcx]
    cmp BYTE[rdi + rcx], dl
    jnz return
    inc rcx
    jmp loop

return:
    movzx rax, BYTE[rdi + rcx]
    movzx rdx, BYTE[rsi + rcx]
    sub rax, rdx
    ret