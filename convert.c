/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asantiag <asantiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 20:50:42 by asantiag          #+#    #+#             */
/*   Updated: 2019/08/24 21:34:40 by asantiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert(int num, int base, int k)
{
	char	*nbr;
	int		size;
	int		tmp;
	int		i;
	

	tmp = num;
	size = 0;
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
