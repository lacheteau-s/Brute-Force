#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "headers.h"
#include "strings.h"
#include "output.h"
#include "utils.h"
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
        if (params->max_entries == 0)
            fd = create_new_file(fd, params);
        write_entry(fd, pwd, params);
        return;
    }

    int len = str_len(params->set);

    for (int i = 0; i < len; ++i)
    {
        if (params->last_entry)
            i = index_of_char(params->last_entry[params->length - length], params->set);

        if ((length < params->length))
        {
            if (params->set[i] == pwd[params->length - length - 1])
            {
                ++i;
                if (i == len)
                    return;
            }
        }

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

void    write_entry(int fd, char *pwd, t_params *params)
{
    if (params->last_entry)
    {
        free(params->last_entry);
        params->last_entry = NULL;
        return;
    }

    write_str(pwd, fd);
    write_char('\n', fd);
    --params->max_entries;    

    return;
}

int    create_new_file(int fd, t_params *params)
{
    ++params->version;

    free(params->file);
    params->file = str_cat(params->path, int_to_str(params->version));
    
    close(fd);
    fd = open(params->file, O_WRONLY | O_APPEND | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);

    params->max_entries = get_max_entries(params);

    return fd;
}
