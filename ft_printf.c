/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asantiag <asantiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 19:53:36 by asantiag          #+#    #+#             */
/*   Updated: 2019/10/09 18:33:52 by asantiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;
	int		d;
	char	c;
	char	*s;
	wchar_t	*ls;

	len = 0;
	va_start(ap, str);
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		else
		{
			i++;
			if (str[i] == 'c' || (str[i] == 'l' && str[i + 1] == 'c'))
			{
				if (str[i] == 'l')
					i++;
				c = (char)va_arg(ap, int);
				ft_putchar(c);
				len--;
			}
			if (str[i] == 's' || (str[i] == 'l' && str[i + 1] == 's'))
			{
				if (str[i] == 'l')
				{
					i++;
					ls = va_arg(ap, wchar_t *);
					len += ft_wstrlen(ls) - 3;
				}
				else
				{
					s = va_arg(ap, char *);
					ft_putstr(s);
					len += ft_strlen(s) - 2;
				}
			}
			if (str[i] == 'd' || str[i] == 'i')
			{
				d = va_arg(ap, int);
				ft_putnbr(d);
				len += ft_nbrlen(d) - 2;
			}
			if (str[i] == 'o')
			{
				d = va_arg(ap, int);
				s = convert(d, 8, 0);
				ft_putstr(s);
				free(s);
				len += ft_nbrlen(d) - 2;
			}
			if (str[i] == 'x')
			{
				d = va_arg(ap, int);
				s = convert(d, 16, 32);
				ft_putstr(s);
				free(s);
				len += ft_nbrlen(d) - 2;
			}
			if (str[i] == 'X')
			{
				d = va_arg(ap, int);
				s = convert(d, 16, 0);
				ft_putstr(s);
				free(s);
				len += ft_nbrlen(d) - 2;
			}
			if (str[i] == 'u')
			{
				d = va_arg(ap, unsigned int);
				ft_putunbr(d);
				len += ft_nbrlen(d) - 2;
			}
		}
		i++;
	}
	va_end(ap);
	return (i + len);
}

/*int	main(void)
{
	ft_printf("ne hui %lcl %s a TbI JIox %d %i %o %x %X %u %ls", 'a', "zalupa konskaya", 21474835698, 321, 23434, 0, 3422, 496729571452584838, "ï");
	return (0);
}
*/