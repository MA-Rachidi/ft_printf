/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 02:41:37 by mrachidi          #+#    #+#             */
/*   Updated: 2020/03/03 23:22:59 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_c(va_list arg)
{
	char	s;
	int		i;

	i = 1;
	ft_initialisation();
	remplir(arg);
	s = va_arg(arg, int);
	if (g_flags.width != 0)
		i = help_c(s);
	else
	{
		ft_putchar(s);
		g_ret++;
	}
	return (i);
}

int		help_c(char s)
{
	int	i;

	i = 0;
	if (g_flags.moins != 0)
	{
		ft_putchar(s);
		g_ret++;
		while (i++ < (g_flags.width - 1))
		{
			ft_putchar(' ');
			g_ret++;
		}
	}
	else
	{
		while (i++ < (g_flags.width - 1))
		{
			ft_putchar(' ');
			g_ret++;
		}
		ft_putchar(s);
		g_ret++;
	}
	return (i);
}
