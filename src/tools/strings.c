char    *str_cpy(char *dest, char *src)
{
    int i = -1;

    while (src[++i])
        dest[i] = src[i];
    dest[i] = '\0';

    return dest;
}

int     str_cmp(char *str1, char *str2)
{
    int i = 0;
    
    while (str1[i] && str2[i] && (str1[i] == str2[i]))
        ++i;        
        
    return str1[i] - str2[i];
}