/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-maj <ouel-maj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:50:46 by ouel-maj          #+#    #+#             */
/*   Updated: 2022/11/11 18:35:10 by ouel-maj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_check(va_list args, const char format)
{
    int val;
    
    val = 0;
    if (format == 'c')
        val += ft_putchar(va_arg(args, int));
    return(val);
}
int ft_printf(const char *str, ...)
{
    int i;
    size_t val;
    va_list args;
    
    i = 0;
    val = 0;
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            val += ft_check(args, str[i + 1]);
            i += 1;
        }
        else
		{
            ft_putchar(str[i]);
			i++;
		}
        i++;
    }
        va_end(args);
        return(val);
    }
int main()
{
	char c = 'B';
	ft_printf("%c", c);
	printf("%c", c);
}