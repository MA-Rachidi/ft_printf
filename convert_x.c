/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:55:29 by mrachidi          #+#    #+#             */
/*   Updated: 2020/03/04 17:55:42 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_x(va_list arg, int j)
{
	unsigned int	i;

	ft_initialisation();
	remplir(arg);
	i = va_arg(arg, unsigned int);
	lenght_x(i);
	if (g_flags.point != 0)
	{
		if (i == 0 && g_flags.width == 0 && g_flags.precision == 0)
			return (1);
		else
			condition_x1(i, j);
	}
	else
	{
		if (g_flags.moins != 0)
			condition_x3(i, j);
		else
			condition_x4(i, j);
	}
	return (g_ret);
}

void	condition_x1(unsigned int h, int j)
{
	if (g_flags.moins != 0)
	{
		if (g_flags.width != 0 && g_flags.precision == 0 && h == 0)
			condition_x5();
		else
			condition_x8(h, j);
	}
	else
		condition_x2(h, j);
}

void	condition_x2(unsigned int h, int j)
{
	if (g_flags.width != 0 && g_flags.precision == 0 && h == 0)
		condition_x5();
	else if (g_flags.point != 0 && g_flags.etoile2 != 0 &&
			g_flags.precision < 0)
		condition_x4(h, j);
	else
		condition_x6(h, j);
}

void	condition_x3(unsigned int i, int h)
{
	int		j;

	j = 0;
	ft_puthex(i, h);
	g_ret = g_ret + g_flags.len;
	while (j++ < (g_flags.width - g_flags.len))
	{
		ft_putchar(' ');
		g_ret++;
	}
}

void	condition_x4(unsigned int i, int h)
{
	int		j;
	char	c;

	j = 0;
	if (g_flags.zero != 0)
		c = '0';
	else
		c = ' ';
	while (j++ < (g_flags.width - g_flags.len))
	{
		ft_putchar(c);
		g_ret++;
	}
	ft_puthex(i, h);
	g_ret = g_ret + g_flags.len;
}
