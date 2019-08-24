/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asantiag <asantiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 19:53:36 by asantiag          #+#    #+#             */
/*   Updated: 2019/08/24 20:45:16 by asantiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		d;
	char	c;
	char	*s;

	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		else
		{
			i++;
			if (str[i] == 'c')
			{
				c = (char)va_arg(ap, int);
				ft_putchar(c);
			}
			if (str[i] == 's')
			{
				s = va_arg(ap, char *);
				ft_putstr(s);
			}
			if (str[i] == 'd')
			{
				d = va_arg(ap, int);
				ft_putnbr(d);
			}
		}
		i++;
	}
	va_end(ap);
	return (1);
}

int		main(void)
{
	ft_printf("ne hui %c %s a ty loh %d", 'a', "zalupa konskaya", 123);
	return (0);
}
