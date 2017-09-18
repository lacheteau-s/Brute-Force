#include <stdlib.h>

#include "headers.h"
#include "opts.h"

int main(int ac, char **av)
{
    t_params    *params = NULL;

    if (!(params = check_opts(ac - 1, av + 1)))
        exit(-1);
    
    free_params(params);

    exit(0);
}

void    free_params(t_params *params)
{
    free(params->set);
    params->set = NULL;

    free(params->file);
    params->file = NULL;

    if (params->last_entry)
    {
        free(params->last_entry);
        params->last_entry = NULL;
    }
}