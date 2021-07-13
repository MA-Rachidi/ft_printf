/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 08:54:45 by mrachidi          #+#    #+#             */
/*   Updated: 2020/03/04 17:41:19 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_u(va_list arg)
{
	unsigned int	i;

	ft_initialisation();
	remplir(arg);
	i = va_arg(arg, unsigned int);
	lenght_d(i);
	if (g_flags.point != 0)
	{
		if (i == 0 && g_flags.width == 0 && g_flags.precision == 0)
			return (1);
		if (g_flags.moins != 0)
			condition_u1(i);
		else
			condition_u2(i);
	}
	else
	{
		if (g_flags.moins != 0)
			condition_u3(i);
		else
			condition_u4(i);
	}
	return (g_ret);
}

void	condition_u1(unsigned int h)
{
	if (g_flags.width != 0 && g_flags.precision == 0 && h == 0)
		condition_u5();
	else
		condition_u8(h);
}

void	condition_u2(unsigned int h)
{
	if (g_flags.width != 0 && g_flags.precision == 0 && h == 0)
		condition_u5();
	else if (g_flags.point != 0 && g_flags.etoile2 != 0 &&
			g_flags.precision < 0)
		condition_u4(h);
	else
		condition_u6(h);
}

void	condition_u3(unsigned int i)
{
	int		j;

	j = 0;
	ft_putunbr(i);
	g_ret = g_ret + g_flags.len;
	while (j++ < (g_flags.width - g_flags.len))
	{
		ft_putchar(' ');
		g_ret++;
	}
}

void	condition_u4(unsigned int i)
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
	ft_putunbr(i);
	g_ret = g_ret + g_flags.len;
}
