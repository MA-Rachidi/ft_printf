/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_pr100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:25:54 by mrachidi          #+#    #+#             */
/*   Updated: 2020/03/03 23:22:19 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_pr100(va_list arg)
{
	int		i;

	i = 0;
	ft_initialisation();
	remplir(arg);
	if (g_flags.moins != 0)
		condition_pr101();
	else
		condition_pr102();
	return (g_ret);
}

void	condition_pr101(void)
{
	int		i;

	i = 0;
	ft_putchar('%');
	g_ret++;
	while (i++ < (g_flags.width - 1))
	{
		ft_putchar(' ');
		g_ret++;
	}
}

void	condition_pr102(void)
{
	int		i;
	char	c;

	i = 0;
	if (g_flags.zero != 0)
		c = '0';
	else
		c = ' ';
	while (i++ < (g_flags.width - 1))
	{
		ft_putchar(c);
		g_ret++;
	}
	ft_putchar('%');
	g_ret++;
}
