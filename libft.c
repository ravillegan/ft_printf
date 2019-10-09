/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asantiag <asantiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 20:36:10 by asantiag          #+#    #+#             */
/*   Updated: 2019/10/09 18:39:53 by asantiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putlchar(wchar_t lc)
{
	write(1, &lc, 2);
}

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar(*s++);
}

void	ft_putlstr(wchar_t const *ls)
{
	if (!ls)
		return ;
	while (*ls)
		ft_putlchar(*ls++);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
		return ;
	}
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
}

void	ft_putunbr(unsigned int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
}

int		ft_strlen(const char *s)
{
	int		l;
	char	*tmp;

	tmp = (char *)s;
	l = 0;
	while (*tmp++)
		l++;
	return (l);
}

int		ft_wstrlen(const wchar_t *ls)
{
	int		l;
	wchar_t	*tmp;

	tmp = (wchar_t *)ls;
	l = 0;
	while (*tmp++)
		l++;
	return (l);
}

int		ft_nbrlen(int num)
{
	int		len;
	
	len = 0;
	if (!num)
		return (1);
	if (num < 0)
		len++;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}
