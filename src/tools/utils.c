#include <sys/stat.h>
#include <stdlib.h>

#include "strings.h"
#include "headers.h"

int     str_is_digits(char *str)
{
    int i = -1;

    while (str[++i])
        if (str[i] < '0' || str[i] > '9')
            return 0;
    return 1;
}

int     int_array_contains(int needle, int haystack[], int len)
{
    int i = -1;

    while (++i < len)
        if (haystack[i] == needle)
            return 1;
    return 0;
}

int     index_of_char(char needle, char *haystack)
{
    int i = -1;

    while (haystack[++i] && (haystack[i] != needle));

    return i;
}

int     index_of_str(char *needle, char **haystack)
{
    int i = -1;

    while (haystack[++i])
        if (!str_cmp(haystack[i], needle))
            return i;            
    return -1;
}

int     str_to_int(char *str)
{
    int ret = 0;
    int i = -1;

    while (str[++i])
    {
        ret += str[i] - '0';

        if (str[i + 1])
            ret *= 10;
    }

    return ret;
}

char    *int_to_str(int nb)
{
    int len = 1;
    int nb2 = nb;

    while (nb2 / 10)
    {
        ++len;
        nb2 /= 10;
    }
    
    char *ret = malloc(len + 1);
    ret[len] = '\0';

    while (len)
    {
        ret[--len] = (nb % 10) + '0';
        nb /= 10;
    }

    return ret;
}

int     get_file_size(char *path)
{
    struct stat *buf = malloc(sizeof(struct stat));

    if (stat(path, buf) < 0)
    {
        return -1;
    }
    return buf->st_size;
}

int     get_max_entries(t_params *params)
{
    struct stat *file_info = malloc(sizeof(struct stat));
    int ret = MAX_FILE_SIZE / (params->length + 1);

    if (stat(params->file, file_info) == 0)
        ret = (MAX_FILE_SIZE - file_info->st_size) / (params->length + 1);

    free(file_info);

    return ret;
}