#include <stdarg.h>
#include <unistd.h>

void    write_char(char c, int fd)
{
    write(fd, &c, 1);
}

void    write_str(char *str, int fd)
{
    int i = -1;

    while (str[++i])
        write_char(str[i], fd);
}

void    write_int(int nb, int fd)
{
    if (nb < 0)
    {
        write_char('-', fd);
        nb *= -1;
    }

    if (nb / 10)
        write_int(nb / 10, fd);
    write_char((nb % 10) + '0', fd);
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
                write_str(s, 1);                
            }
            else if (str[i] == 'c')
            {
                char c = va_arg(ap, int);
                write_char(c, 1);
            }
            else if (str[i] == 'd')
            {
                int i = va_arg(ap, int);
                write_int(i, 1);
            }
            else
                write_char(str[i], 1);
        }
        else
            write_char(str[i], 1);
    }
    
    va_end(ap);
}