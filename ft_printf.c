/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-maj <ouel-maj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:50:46 by ouel-maj          #+#    #+#             */
/*   Updated: 2022/11/16 12:34:21 by ouel-maj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"
#include <stdlib.h>
#include <unistd.h>


int	ft_printchar(char c)
{
	write(1, &c, 1);
    return (1);
}

int ft_printstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return(i);
}

size_t    ft_strlen( const char *str)
{
    size_t    i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}
char    *ft_strdup(const char *s1)
{
    int        i;
    char    *dest;
    char    *x;

    i = 0;
    x = ((dest = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1)));
    if (!x)
    {
        return (0);
    }
    while (s1[i])
    {
        dest[i] = s1[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
int    ft_checklen(int n)
{
    int    len;

    if (n == 0)
        return (1);
    len = 0;
    if (n < 0)
        len++;
    while (n != 0)
    {
        n = n / 10;
        len++;
    }
    return (len);
}
char    *ft_itoa(int n)
{
    int        len;
    char    *res;
    char    modulo;

    if (n == 0)
        return (ft_strdup("0"));
    len = ft_checklen(n);
    res = malloc(sizeof(char) * (len + 1));
    if (res == NULL)
        return (NULL);
    if (n < 0)
        res[0] = '-';
    res[len] = '\0';
    while (n != 0)
    {
        len--;
        modulo = n % 10;
        if (n < 0)
            modulo *= -1;
        res[len] = modulo + '0';
        n /= 10;
    }
    return (res);
}

int ft_printnbr(int len)
{
    char *c;
    
    c = ft_itoa(len);
    printf("Itoa : %s", c);
    len = ft_printstr(c);
    free(c);
    return(len);
}
int format(va_list args, const char format)
{
    int print_length;

    print_length = 0;
    if (format == 'c')
        print_length += ft_printchar(va_arg(args, int));
    else if (format == 's')
    {
        print_length += ft_printstr(va_arg(args, char *));
    }
    else if (format == 'd')
    {
        print_length += ft_printnbr(va_arg(args, int));
    }
    
    return(print_length);
}
int     ft_printf(const char *str, ...)
{
    int i;
    int print_length;

    print_length = 0;
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
    ft_printf("%d", 123);
}