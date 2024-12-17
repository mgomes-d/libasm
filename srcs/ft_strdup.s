global ft_strdup
extern __errno_location
extern malloc
extern ft_strcpy
extern ft_strlen

; rdi = const char *s

; malloc(size)
ft_strdup:
    cmp rdi, 0
    jz error_null
    call ft_strlen WRT ..plt ; i have len in rax
    inc rax ; add +1 for the \0
    push rdi ; not losing rsi
    mov rdi, rax ; put as arg to pass to malloc
    call malloc WRT ..plt ; now i have the pointer in rax
    cmp rax, 0
    je error
    mov rdi, rax ; put the return in rax
    pop rsi ; i have the source in rsi
    call ft_strcpy WRT ..plt ; copy the source in dest, at rax
    ret

error_null:
    mov rax, 22
    mov rdi, rax
    call __errno_location WRT ..plt
    mov [rax], edi ; change the value pointed bt rax
    mov rax, 0
    ret

error:
    neg rax
    mov rdi, rax
    call __errno_location WRT ..plt
    mov [rax], edi ; change the value pointed bt rax
    mov rax, -1
    ret