#ifndef __OPTS_H__
#define __OPTS_H__

#define MAX_OPTS    5
#define OPT_LEN     2

#define OPT_S       0
#define OPT_L       1
#define OPT_F       2
#define OPT_R       3
#define OPT_V       4

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
    NUM_OPTS_VALIDATION,
    END
};

t_params    *check_opts(int, char **);
t_opts      *init_opts(int, char **);
t_params    *init_params(t_opts *);
int         validate_opts_count(t_opts *);
int         validate_opts(t_opts *);
int         validate_numeric_opts(t_opts *);
int         set_opts_idx(t_opts *);
int         set_args_idx(t_opts *);
void        free_opts(t_opts *, int);

#endif