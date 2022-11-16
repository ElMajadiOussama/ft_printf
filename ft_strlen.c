#include "printf.h"
// int ft_strlen(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i])
//     {
//         i++;
//     }
//     return (i);
// }
size_t	ft_strlen( const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}