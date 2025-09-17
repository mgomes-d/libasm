**Libasm**
A custom C library rewritten entirely in **x86-64 Assembly (Intel syntax, NASM)** to explore low-level programming and system calls.

**Description:**
This project is an introduction to assembly language programming. I reimplemented several standard C library functions in pure assembly, focusing on understanding calling conventions, memory management, and system-level operations.

**Implemented functions (mandatory part):**

* `ft_strlen` – calculate string length
* `ft_strcpy` – copy a string
* `ft_strcmp` – compare two strings
* `ft_write` – write to a file descriptor (with error handling)
* `ft_read` – read from a file descriptor (with error handling)
* `ft_strdup` – duplicate a string (using `malloc`)

**Key learnings:**

* Writing and compiling 64-bit assembly with NASM
* Handling system calls and managing `errno` correctly
* Linking assembly with C code to build functional libraries
