#include <stdlib.h>

#include "opts.h"

int main(int ac, char **av)
{
    if (check_opts(ac - 1, av + 1) == -1)
        exit(-1);
    exit(0);
}