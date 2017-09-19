#include <stdlib.h>

#include "strings.h"

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

char    *str_dup(char *src)
{
    int     len = str_len(src);
    char    *ret = malloc(len + 1);

    if (ret == NULL)
        return NULL;

    int i = -1;

    while (src[++i])
        ret[i] = src[i];
    ret[i] = '\0';

    return ret;
}

int     str_len(char *src)
{
    int i = 0;

    while (src[++i]);

    return i;
}

char    *str_cat(char *s1, char *s2)
{
    char *ret = malloc(str_len(s1) + str_len(s2) + 1);

    int i = -1;

    while (s1[++i])
        ret[i] = s1[i];

    int j = -1;

    while (s2[++j])
        ret[i++] = s2[j];

    ret[i] = '\0';

    return ret;
}