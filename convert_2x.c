/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_2x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:48:35 by mrachidi          #+#    #+#             */
/*   Updated: 2020/03/04 17:39:03 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	condition_x5(void)
{
	int		i;

	i = 0;
	while (i++ < g_flags.width)
	{
		ft_putchar(' ');
		g_ret++;
	}
}

void	condition_x6(unsigned int h, int k)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (g_flags.precision > g_flags.len)
		j = g_flags.precision - g_flags.len;
	while (i++ < (g_flags.width - (g_flags.len + j)))
	{
		ft_putchar(' ');
		g_ret++;
	}
	i = 0;
	while (i++ < j)
	{
		ft_putchar('0');
		g_ret++;
	}
	ft_puthex(h, k);
	g_ret = g_ret + g_flags.len;
}

void	condition_x7(unsigned int h, int k)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (g_flags.precision > g_flags.len)
		j = g_flags.precision - g_flags.len + 1;
	while (i++ < (g_flags.width - (g_flags.len + j)))
	{
		ft_putchar(' ');
		g_ret++;
	}
	ft_putchar('-');
	i = 0;
	while (i++ < j)
	{
		ft_putchar('0');
		g_ret++;
	}
	ft_puthex(-h, k);
	g_ret = g_ret + g_flags.len;
}

void	condition_x8(unsigned int h, int k)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (g_flags.precision > g_flags.len)
		j = g_flags.precision - g_flags.len;
	while (i++ < j)
	{
		ft_putchar('0');
		g_ret++;
	}
	ft_puthex(h, k);
	g_ret = g_ret + g_flags.len;
	i = 0;
	while (i++ < (g_flags.width - (g_flags.len + j)))
	{
		ft_putchar(' ');
		g_ret++;
	}
}

void	condition_x9(unsigned int h, int k)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (g_flags.precision > g_flags.len)
		j = g_flags.precision - g_flags.len + 1;
	ft_putchar('-');
	while (i++ < j)
	{
		ft_putchar('0');
		g_ret++;
	}
	ft_puthex(-h, k);
	g_ret = g_ret + g_flags.len;
	i = 0;
	while (i++ < (g_flags.width - (g_flags.len + j)))
	{
		ft_putchar(' ');
		g_ret++;
	}
}
