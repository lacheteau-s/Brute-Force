#ifndef __OPTS_H__
#define __OPTS_H__

#define MAX_OPTS    4
#define OPT_LEN     2

#define OPT_S       0
#define OPT_L       1
#define OPT_F       2
#define OPT_E       3

typedef struct s_opts
{
    int     ac;
    char    **av;
    char    **opts;
    int     *opts_idx;
    int     *args_idx;
} t_opts;

enum state
{
    OPTS_COUNT,
    OPTS_IDX,
    ARGS_IDX,
    OPTS_VALIDATION,
    LENGTH_VALIDATION,
//    LENGTH_VS_SET_VALIDATION,
    END
};

int     check_opts(int, char **);
t_opts  *init_opts(int, char **);
int     validate_opts_count(t_opts *);
int     validate_opts(t_opts *);
int     validate_length_opt(t_opts *);
int     set_opts_idx(t_opts *);
int     set_args_idx(t_opts *);
void    free_opts(t_opts *, int);

#endif