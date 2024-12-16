.text:
    global ft_strcpy

ft_strcpy:
    push rdi

.loopy:
    mov al, [rsi]
    mov [rdi], al
    inc rsi
    inc rdi
    test al, al ; check if null
    jnz .loopy

    pop rax
    ret

