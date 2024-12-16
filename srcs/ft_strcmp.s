.text:
    global ft_strcmp

ft_strcmp:  

.loopy:
    mov al, [rdi]
    mov bl, [rsi]
    cmp al, bl
    jne .return
    test al, al
    je .return
    inc rdi
    inc rsi
    jmp .loopy

.return:
    sub al, bl          
    seta cl             
    setb dl
    sub cl, dl
    movsx rax, cl 
    ret    
