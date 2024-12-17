char *strcpy(char *dest, const char *src){
    size_t i = 0;
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    return dest;
}