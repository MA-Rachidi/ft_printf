/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 08:54:45 by mrachidi          #+#    #+#             */
/*   Updated: 2020/03/03 23:28:00 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_di(va_list arg)
{
	int		i;

	ft_initialisation();
	remplir(arg);
	i = va_arg(arg, int);
	lenght_d(i);
	if (g_flags.point != 0)
	{
		if (i == 0 && g_flags.width == 0 && g_flags.precision == 0)
			return (1);
		if (g_flags.moins != 0)
			condition_d1(i);
		else
			condition_d2(i);
	}
	else
	{
		if (g_flags.moins != 0)
			condition_d3(i);
		else
			condition_d4(i);
	}
	return (g_ret);
}

void	condition_d1(int h)
{
	if (g_flags.width != 0 && g_flags.precision == 0 && h == 0)
		condition_d5();
	else if (h < 0)
		condition_d9(h);
	else
		condition_d8(h);
}

void	condition_d2(int h)
{
	if (g_flags.width != 0 && g_flags.precision == 0 && h == 0)
		condition_d5();
	else if (g_flags.point != 0 && g_flags.etoile2 != 0 &&
			g_flags.precision < 0)
		condition_d4(h);
	else if (h < 0)
		condition_d7(h);
	else
		condition_d6(h);
}

void	condition_d3(int i)
{
	int		j;

	j = 0;
	ft_putnbr(i);
	g_ret = g_ret + g_flags.len;
	while (j++ < (g_flags.width - g_flags.len))
	{
		ft_putchar(' ');
		g_ret++;
	}
}

void	condition_d4(int i)
{
	int		j;
	char	c;

	j = 0;
	if (g_flags.zero != 0)
		c = '0';
	else
		c = ' ';
	if (g_flags.zero != 0 && i < 0)
		ft_putchar('-');
	while (j++ < (g_flags.width - g_flags.len))
	{
		ft_putchar(c);
		g_ret++;
	}
	if (g_flags.zero != 0 && i < 0)
	{
		if (i == -2147483648)
			ft_putunbr(-i);
		else
			ft_putnbr(-i);
	}
	else
		ft_putnbr(i);
	g_ret = g_ret + g_flags.len;
}
