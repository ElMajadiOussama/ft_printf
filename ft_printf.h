#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

void    ft_putchar(char c);
void    ft_putnbr(int nb);
int     ft_strlen(char *str);
int     ft_printf(const char *, ...);

#endif