#ifndef __HEADERS_H__
#define __HEADERS_H__

#define MAX_FILE_SIZE 1000000000

typedef struct s_params
{
    char    *set;
    int     length;
    char    *path;
    int     version;
    char    *last_entry;
    int     max_entries;
    char    *file;
} t_params;

void    free_params(t_params *);

#endif