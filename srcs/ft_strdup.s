.text:
    global ft_strdup
    extern malloc


ft_strdup:
    mov eax, 285
    syscall
    ret
