global ft_read
extern __errno_location

ft_read:
    mov rax, 0
    syscall
    cmp rax, 0
    jge success

error:
    neg rax
    mov rdi, rax
    call __errno_location WRT ..plt
    mov [rax], edi
    mov rax, -1

success:
    ret