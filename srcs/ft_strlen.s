section .text
	global ft_strlen

ft_strlen:
	xor  rcx, rcx

.strlen_loop:
	cmp byte [rdi + rcx], 0
	je .return
	inc rcx
	jmp .strlen_loop

.return:
	mov rax, rcx
	ret