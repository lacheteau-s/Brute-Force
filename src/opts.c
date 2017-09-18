#include <stdlib.h>

#include "headers.h"
#include "strings.h"
#include "output.h"
#include "utils.h"
#include "opts.h"

t_params     *check_opts(int ac, char **av)
{
    t_opts      *opts = init_opts(ac, av);

    if (opts == NULL)
        return NULL;
    
    int state = OPTS_COUNT;
    int (*func[])(t_opts *) =
    {
        validate_opts_count,
        set_opts_idx,
        set_args_idx,
        validate_opts,
        validate_length_opt
    };

    while (state < END)
    {
        if (func[state](opts) < 0)
        {
            free_opts(opts, state);
            return NULL;
        }

        ++state;
    }

    t_params *params = init_params(opts);
    free_opts(opts, state);

    return params;
}

t_opts      *init_opts(int ac, char **av)
{
    char    options[MAX_OPTS][OPT_LEN + 1] = { "-s", "-l", "-f", "-e" };
    t_opts  *opts = malloc(sizeof(t_opts)); // TODO: Error handling

    opts->ac = ac;
    opts->av = av;
    opts->opts = malloc(MAX_OPTS * sizeof(char *)); // TODO: Error handling

    for (int i = 0; i < MAX_OPTS; ++i)
        opts->opts[i] = str_dup(options[i]);

    return opts;
}

t_params    *init_params(t_opts *opts)
{
    t_params    *params = malloc(sizeof(t_params)); // TODO: Error handling

    params->set = str_dup(opts->av[opts->args_idx[OPT_S]]);
    params->length = str_to_int(opts->av[opts->args_idx[OPT_L]]);
    params->file = str_dup(opts->av[opts->args_idx[OPT_F]]);
    params->last_entry = (opts->opts_idx[OPT_E] < 0) ? NULL : str_dup(opts->av[opts->args_idx[OPT_E]]);

    return params;
}

int         validate_opts_count(t_opts *opts)
{
    if (opts->ac < 6 || opts->ac > 8 || opts->ac == 7)
    {
        write_str("Invalid number of arguments.\n");
        return -1;
    }
    return 0;
}

int         validate_opts(t_opts *opts)
{
    for (int idx = 0; idx < MAX_OPTS; ++idx)
    {
        if ((opts->opts_idx[idx] < 0) && (idx != OPT_E)) // Checks if mandatory options are provided
        {
            write_line("Missing option %s.\n", opts->opts[idx]);
            return -1;
        }
        else if ((opts->opts_idx[idx] != -1) && (opts->args_idx[idx] < 0)) // Checks if argument for mandatory options is provided
        {
            write_line("Missing argument for option %s.\n", opts->opts[idx]);
            return -1;
        }
    }

    return 0;
}

int         validate_length_opt(t_opts *opts)
{
    if (!str_is_digits(opts->av[opts->args_idx[OPT_L]]))
    {
        write_str("Argument for option -l must be a whole number.\n");
        return -1;
    }

    return 0;
}

int         set_opts_idx(t_opts *opts)
{
    opts->opts_idx = malloc(MAX_OPTS * sizeof(int));

    for (int i = 0; i < MAX_OPTS; ++i)
        opts->opts_idx[i] = index_of_str(opts->opts[i], opts->av);
    return 0;
}

int         set_args_idx(t_opts *opts)
{
    opts->args_idx = malloc(MAX_OPTS * sizeof(int));

    for (int i = 0; i < MAX_OPTS; ++i)
    {
        int idx = opts->opts_idx[i] + 1;
        opts->args_idx[i] = ((idx >= opts->ac) || int_array_contains(idx, opts->opts_idx, MAX_OPTS)) ? -1 : idx;
    }
    return 0;
}

void        free_opts(t_opts *opts, int state)
{
    for (int i = 0; i < MAX_OPTS; ++i)
    {
        free(opts->opts[i]);
        opts->opts[i] = NULL;        
    }
    free(opts->opts);
    opts->opts = NULL;

    if (state > OPTS_IDX)
    {
        free(opts->opts_idx);
        opts->opts_idx = NULL;
    }
    
    if (state > ARGS_IDX)
    {
        free(opts->args_idx);
        opts->args_idx = NULL;
    }

    free(opts);
    opts = NULL;
}