decompile a C code to asm.

gcc -S ft_strlen.c -o ft_strlen.s


nasm -f macho64 ft_strlen.s -o ft_strlen.o
gcc 