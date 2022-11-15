#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "printf.h"

// int max(int num_args, ...);


// int max(int num_args, ...)
// {
//     int i = 0;
//     int x;
//     va_list args;
//     va_start(args, num_args);

//     int max = 0;
//     while (i < num_args)
//     {
//         x = va_arg(args, int);
//         if(i == 0)
//             max = x;
//         else if (max < x)
//             max = x;
//         i++;
//     }
//     return (max);
    // if (a < b)
    //     return a;
    // else
    //     return b;
// }

int	ft_printchar(char c)
{
	write(1, &c, 1);
    return (1);
}
int format(va_list args, const char format)
{
    int print_length;
    if (format == 'c')
        print_length += ft_printchar(va_arg(args, int));
    
    return(print_length);
}
int     ft_printf(const char *str, ...)
{
    int i;
    int print_length;

    i = 0;
    va_list args;
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            print_length += format(args, str[i + 1]);
            i++;
        }
    }
    va_end(args);
    return (print_length);
}

int main(void)
{
    ft_printf("%c", 'a');
}