/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asantiag <asantiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 20:50:42 by asantiag          #+#    #+#             */
/*   Updated: 2019/10/09 18:16:42 by asantiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert(int num, int base, int k)
{
	char	*nbr;
	int		size;
	int		tmp;

	tmp = num;
	size = 0;
	if (!num)
	{
		if (!(nbr = (char *)malloc(sizeof(char) * 2)))
			return (0);
		nbr[0] = '0';
		nbr[1] = '\0';
		return (nbr);
	}
	while (tmp)
	{
		tmp /= base;
		size++;
	}
	if (!(nbr = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	nbr[size] = '\0';
	while (num)
	{
		if (num % base > 9)
			nbr[size - 1] = num % base - 10 + 'A' + k;
		else
			nbr[size - 1] = num % base + '0';
		num /= base;
		size--;
	}
	return (nbr);
}
