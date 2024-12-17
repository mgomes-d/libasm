int strcmp(const char *s1, const char *s2)
{
    int i = 0;
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    if (s1[i] - s2[i])
        return 1
    return -1;
}