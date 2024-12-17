#include <stddef.h>
#include <aio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *dest, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
// char    *ft_strdup(const char *s);
// int strcmp(const char *s1, const char *s2)
// {
//     int i = 0;
//     while (s1[i] && s2[i] && s1[i] == s2[i])
//         i++;
//     if (s1[i] - s2[i])
//         return 1;
//     else
//         return -1;
// }
int main()
{
    // ft_strlen
    printf("Testing ft_strlen:\n");
    printf("Length of 'Hello' = %ld\n", ft_strlen("Hello"));
    printf("Length of '' = %ld\n", ft_strlen(""));
    printf("Length of '1234567890' = %ld\n", ft_strlen("1234567890"));

    printf("Original strlen:\n");
    printf("Length of 'Hello' = %ld\n", strlen("Hello"));
    printf("Length of '' = %ld\n", strlen(""));
    printf("Length of '1234567890' = %ld\n", strlen("1234567890"));

    // ft_strcpy
    printf("\nTesting ft_strcpy:\n");
    char *src = "Hello World";
    char *dest = calloc(ft_strlen(src) + 1, sizeof(char));
    printf("Source: %s\n", src);
    printf("Destination before copy: %s\n", dest);
    ft_strcpy(dest, src);
    printf("Destination after copy: %s\n", dest);
    free(dest);

    printf("Original strcpy:\n");
    dest = calloc(ft_strlen(src) + 1, sizeof(char));
    printf("Source: %s\n", src);
    printf("Destination before copy: %s\n", dest);
    strcpy(dest, src);
    printf("Destination after copy: %s\n", dest);
    free(dest);

    // ft_strcmp
    printf("\nTesting ft_strcmp:\n");
    printf("ft_strcmp('Hello', 'Hello') = %d\n", ft_strcmp("Hello", "Hello"));
    printf("ft_strcmp('Hello', 'Hell') = %d\n", ft_strcmp("Hello", "Hell"));
    printf("ft_strcmp('Hell', 'Hello') = %d\n", ft_strcmp("Hell", "Hello"));
    printf("ft_strcmp('Helloz', 'Hellog') = %d\n", ft_strcmp("Helloz", "Hellog"));

    printf("strcmp('Hello', 'Hello') = %d\n", strcmp("Hello", "Hello"));
    printf("strcmp('Hello', 'Hell') = %d\n", strcmp("Hello", "Hell"));
    printf("strcmp('Hell', 'Hello') = %d\n", strcmp("Hell", "Hello"));
    printf("strcmp('Helloz', 'Hellog') = %d\n", strcmp("Helloz", "Hellog"));

    // // ft_write
    // printf("\nTesting ft_write:\n");
    // ssize_t bytes_written = ft_write(1, "Hello World\n", 12);
    // printf("Bytes written: %ld\n", bytes_written);

    // // ft_read
    // printf("\nTesting ft_read:\n");
    // char buffer[13];
    // ssize_t bytes_read = ft_read(0, buffer, 12);
    // buffer[bytes_read] = '\0'; // Null-terminate the string
    // printf("Bytes read: %ld\n", bytes_read);
    // printf("Buffer: %s\n", buffer);

    // ft_strdup
    // printf("\nTesting ft_strdup:\n");
    // char *original = "Hello strdup";
    // char *duplicate = ft_strdup(original);
    // if (duplicate) {
    //     printf("Original: %s\n", original);
    //     printf("Duplicate: %s\n", duplicate);
    //     free(duplicate);
    // } else {
    //     printf("ft_strdup failed to allocate memory\n");
    // }

    // return 0;
}