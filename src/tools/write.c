#include <stdarg.h>

void    write_char(char c, int fd)
{
    write(fd, &c, 1);
}

void    write_str(char *str, int fd)
{
    int i = -1;

    while (str[++i])
        write_char(str[i]);
}

void    write_line(const char *str, ...)
{
    va_list ap;
    va_start(ap, str);

    while (*str)
    {
        if ((*str == '%') && (*(str + 1)))
        {
            ++str;
            if (*str == 's')
            {
                char *s = va_arg(ap, char *);
                write_str(s);                
            }
            else if (*str == 'c')
            {
                char c = va_arg(ap, int);
                write_char(c);
            }
            else if (*str == 'd')
            {
                int i = va_arg(ap, int);
                write_int(i);
            }
            else
                write_char(*str);
        }
        else
            write_char(*str);
        ++str;
    }
    
    va_end(ap);
}