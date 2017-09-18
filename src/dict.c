#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "headers.h"
#include "strings.h"
#include "output.h"
#include "dict.h"

void    write_dictionary(t_params *params)
{
    int fd = open(params->file, O_WRONLY | O_APPEND | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);

    write_dictionary_rec(fd, "", params->length, params);

    close(fd);
}

void    write_dictionary_rec(int fd, char *pwd, int length, t_params *params)
{
    if (length == 0)
    {
        write_str(pwd, fd);
        write_char('\n', fd);
        return;
    }

    for (int i = 0; i < str_len(params->set); ++i)
    {
        char *str = malloc(str_len(pwd) + 2);
        int j = -1;

        while (pwd[++j])
            str[j] = pwd[j];
        str[j++] = params->set[i];
        str[j] = '\0';

        write_dictionary_rec(fd, str, length - 1, params);
        free(str);
    }
}
