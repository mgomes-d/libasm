global ft_strlen
section .text

ft_strlen:
	xor rax, rax

loop:
	cmp byte[rdi + rax], 0
	jz return
	inc rax
	jmp loop

return:
	ret