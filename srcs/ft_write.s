global ft_write
extern __errno_location

ft_write:
    mov rax, 1
    syscall
    cmp rax, 0
    jge success

error:
    neg rax
    mov rdi, rax
    call __errno_location WRT ..plt
    mov [rax], edi ; change the value pointed bt rax
    mov rax, -1
    
success:
    ret