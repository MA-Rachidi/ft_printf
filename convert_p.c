/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:00:03 by mrachidi          #+#    #+#             */
/*   Updated: 2020/03/04 17:55:01 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_p(va_list arg, int j)
{
	unsigned long	i;
	int				h;

	h = 0;
	ft_initialisation();
	remplir(arg);
	i = va_arg(arg, unsigned long);
	if (!(i == 0 && g_flags.point != 0))
		lenght_x(i);
	g_flags.len = g_flags.len + 2;
	condition_p1(i, j);
	return (g_ret);
}

void	condition_p1(unsigned long i, int j)
{
	int				h;

	h = 0;
	if (g_flags.moins != 0)
	{
		ft_putchar('0');
		ft_putchar('x');
		if (!(i == 0 && g_flags.point != 0))
			ft_puthex(i, j);
		g_ret = g_ret + g_flags.len;
		while (h++ < (g_flags.width - g_flags.len))
		{
			ft_putchar(' ');
			g_ret++;
		}
	}
	else
		condition_p2(i, j);
}

void	condition_p2(unsigned long i, int j)
{
	int				h;

	h = 0;
	while (h++ < (g_flags.width - g_flags.len))
	{
		ft_putchar(' ');
		g_ret++;
	}
	ft_putchar('0');
	ft_putchar('x');
	if (!(i == 0 && g_flags.point != 0))
		ft_puthex(i, j);
	g_ret = g_ret + g_flags.len;
}
