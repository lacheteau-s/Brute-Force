#ifndef __HEADERS_H__
#define __HEADERS_H__

typedef struct s_params
{
    char    *set;
    int     length;
    char    *file;
    char    *last_entry;
} t_params;

void    free_params(t_params *);

#endif