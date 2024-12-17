#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

// Function declarations
size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *dest, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char    *ft_strdup(const char *s);

int main(){
    // ft_strlen
    const char *test_str1 = "Hello, World!";
    const char *test_str2 = "";
    const char *test_str3 = "1234567890";

    printf("Testing ft_strlen...\n");
    printf("Input: \"%s\", Expected: %zu, Got: %zu\n", test_str1, strlen(test_str1), ft_strlen(test_str1));
    printf("Input: \"%s\", Expected: %zu, Got: %zu\n", test_str2, strlen(test_str2), ft_strlen(test_str2));
    printf("Input: \"%s\", Expected: %zu, Got: %zu\n", test_str3, strlen(test_str3), ft_strlen(test_str3));

    // ft_strcpy
    char dest1[50];
    char dest2[50];
    char dest3[50];

    printf("\nTesting ft_strcpy...\n");
    printf("Input: \"%s\", Expected: \"%s\", Got: \"%s\"\n", test_str1, strcpy(dest1, test_str1), ft_strcpy(dest1, test_str1));
    printf("Input: \"%s\", Expected: \"%s\", Got: \"%s\"\n", test_str2, strcpy(dest2, test_str2), ft_strcpy(dest2, test_str2));
    printf("Input: \"%s\", Expected: \"%s\", Got: \"%s\"\n", test_str3, strcpy(dest3, test_str3), ft_strcpy(dest3, test_str3));

    // ft_strcmp

    const char *cmp_str1 = "abc";
    const char *cmp_str2 = "abc";
    const char *cmp_str3 = "abcd";
    const char *cmp_str4 = "ab";

    printf("\nTesting ft_strcmp...\n");
    printf("Input: \"%s\" vs \"%s\", Expected: %d, Got: %d\n", cmp_str1, cmp_str2, strcmp(cmp_str1, cmp_str2), ft_strcmp(cmp_str1, cmp_str2));
    printf("Input: \"%s\" vs \"%s\", Expected: %d, Got: %d\n", cmp_str1, cmp_str3, strcmp(cmp_str1, cmp_str3), ft_strcmp(cmp_str1, cmp_str3));
    printf("Input: \"%s\" vs \"%s\", Expected: %d, Got: %d\n", cmp_str1, cmp_str4, strcmp(cmp_str1, cmp_str4), ft_strcmp(cmp_str1, cmp_str4));
    printf("Input: \"%s\" vs \"%s\", Expected: %d, Got: %d\n", cmp_str3, cmp_str4, strcmp(cmp_str3, cmp_str4), ft_strcmp(cmp_str3, cmp_str4));

    // ft_write
    const char *write_str = "Hello, World!";
    ssize_t write_ret, ft_write_ret;

    printf("\nTesting ft_write...\n");
    write_ret = write(STDOUT_FILENO, write_str, strlen(write_str));
    printf("\nExpected: %zd, ", write_ret);
    ft_write_ret = ft_write(STDOUT_FILENO, write_str, strlen(write_str));
    printf("Got: %zd\n", ft_write_ret);

    // Test ft_write with invalid file descriptor to check errno
    printf("\nTesting ft_write with invalid file descriptor...\n");
    errno = 0;
    write_ret = write(-1, write_str, strlen(write_str));
    int write_errno = errno;
    errno = 0;
    ft_write_ret = ft_write(-1, write_str, strlen(write_str)); // Fixed call to ft_write
    int ft_write_errno = errno;
    printf("Expected: %zd, errno: %d, Got: %zd, errno: %d\n", write_ret, write_errno, ft_write_ret, ft_write_errno);

    // ft_read
    char buffer[50];
    ssize_t read_ret, ft_read_ret;
    int read_errno, ft_read_errno;

    printf("\nTesting ft_read...\n");
    int fd = open("testfile.txt", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open testfile.txt");
        return 1;
    }
    read_ret = read(fd, buffer, sizeof(buffer) - 1);
    if (read_ret >= 0) buffer[read_ret] = '\0';
    printf("Expected: %zd, Got: %zd, Buffer: \"%s\"\n", read_ret, read_ret, buffer);

    lseek(fd, 0, SEEK_SET); // Reset file offset
    ft_read_ret = ft_read(fd, buffer, sizeof(buffer) - 1);
    if (ft_read_ret >= 0) buffer[ft_read_ret] = '\0';
    printf("Expected: %zd, Got: %zd, Buffer: \"%s\"\n", read_ret, ft_read_ret, buffer);
    close(fd);

    // Test ft_read with invalid file descriptor to check errno
    printf("\nTesting ft_read with invalid file descriptor...\n");
    errno = 0;
    read_ret = read(-1, buffer, sizeof(buffer) - 1);
    read_errno = errno;
    errno = 0;
    ft_read_ret = ft_read(-1, buffer, sizeof(buffer) - 1);
    ft_read_errno = errno;
    printf("Expected: %zd, errno: %d, Got: %zd, errno: %d\n", read_ret, read_errno, ft_read_ret, ft_read_errno);

    // ft_strdup
    char *dup_str1, *dup_str2, *dup_str3;

    printf("\nTesting ft_strdup...\n");
    dup_str1 = ft_strdup(test_str1);
    printf("Input: \"%s\", Got: \"%s\"\n", test_str1, dup_str1);
    free(dup_str1);

    dup_str2 = ft_strdup(test_str2);
    printf("Input: \"%s\", Got: \"%s\"\n", test_str2, dup_str2);
    free(dup_str2);

    dup_str3 = ft_strdup(test_str3);
    printf("Input: \"%s\", Got: \"%s\"\n", test_str3, dup_str3);
    free(dup_str3);

    // Test ft_strdup with NULL to check errno
    printf("\nTesting ft_strdup with NULL...\n");
    errno = 0;
    dup_str2 = ft_strdup(NULL);
    int ft_strdup_errno = errno;
    printf("Got: %p, errno: %d\n", dup_str2, ft_strdup_errno);

    return 0;
}