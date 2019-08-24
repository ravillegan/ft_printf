/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asantiag <asantiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 20:37:58 by asantiag          #+#    #+#             */
/*   Updated: 2019/08/24 21:30:49 by asantiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
void	ft_putnbr(int n);
int		ft_printf(const char *str, ...);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
char	*convert(int num, int base, int k);

#endif