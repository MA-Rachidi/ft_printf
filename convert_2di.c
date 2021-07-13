/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_2di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:48:35 by mrachidi          #+#    #+#             */
/*   Updated: 2020/03/03 23:24:45 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	condition_d5(void)
{
	int		i;

	i = 0;
	while (i++ < g_flags.width)
	{
		ft_putchar(' ');
		g_ret++;
	}
}

void	condition_d6(int h)
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
	ft_putnbr(h);
	g_ret = g_ret + g_flags.len;
}

void	condition_d7(int h)
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
	if (h == -2147483648)
		ft_putunbr(-h);
	else
		ft_putnbr(-h);
	g_ret = g_ret + g_flags.len;
}

void	condition_d8(int h)
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
	ft_putnbr(h);
	g_ret = g_ret + g_flags.len;
	i = 0;
	while (i++ < (g_flags.width - (g_flags.len + j)))
	{
		ft_putchar(' ');
		g_ret++;
	}
}

void	condition_d9(int h)
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
	if (h == -2147483648)
		ft_putunbr(-h);
	else
		ft_putnbr(-h);
	g_ret = g_ret + g_flags.len;
	i = 0;
	while (i++ < (g_flags.width - (g_flags.len + j)))
	{
		ft_putchar(' ');
		g_ret++;
	}
}
