#include <stdarg.h>
#include <unistd.h>

void    write_char(char c)
{
    write(1, &c, 1);
}

void    write_str(char *str)
{
    int i = -1;

    while (str[++i])
        write_char(str[i]);
}

void    write_int(int nb)
{
    if (nb < 0)
    {
        write_char('-');
        nb *= -1;
    }

    if (nb / 10)
        write_int(nb / 10);
    write_char((nb % 10) + '0');
}

void    write_line(const char *str, ...)
{
    va_list ap;
    va_start(ap, str);
    int i = -1;

    while (str[++i])
    {
        if ((str[i] == '%') && (str[i + 1]))
        {
            ++i;
            if (str[i] == 's')
            {
                char *s = va_arg(ap, char *);
                write_str(s);                
            }
            else if (str[i] == 'c')
            {
                char c = va_arg(ap, int);
                write_char(c);
            }
            else if (str[i] == 'd')
            {
                int i = va_arg(ap, int);
                write_int(i);
            }
            else
                write_char(str[i]);
        }
        else
            write_char(str[i]);
    }
    
    va_end(ap);
}