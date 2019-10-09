/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asantiag <asantiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 20:37:58 by asantiag          #+#    #+#             */
/*   Updated: 2019/10/09 18:33:41 by asantiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MAX_INT 2147483647

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
void	ft_putnbr(int n);
int		ft_printf(const char *str, ...);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
char	*convert(int num, int base, int k);
void	ft_putunbr(unsigned int n);
void	ft_putlstr(wchar_t const *s);
int     ft_strlen(const char *s);
int		ft_nbrlen(int num);
int		ft_wstrlen(const wchar_t *ls);

#endif