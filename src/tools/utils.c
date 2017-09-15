#include "strings.h"

int str_is_digits(char *str)
{
    int i = -1;

    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
            return 0;
    return 1;
}

int int_array_contains(int needle, int haystack[], int len)
{
    int i = -1;

    while (++i < len)
        if (haystack[i] == needle)
            return 1;
    return 0;
}

int index_of_str(char *needle, char **haystack)
{
    int i = -1;

    while (haystack[++i])
        if (!str_cmp(haystack[i], needle))
            return i;            
    return -1;
}