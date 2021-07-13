/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 02:45:18 by mrachidi          #+#    #+#             */
/*   Updated: 2020/03/04 17:48:43 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		remplissage3(int i, va_list arg)
{
	int	j;

	j = i;
	g_flags.width = va_arg(arg, int);
	if (g_flags.width < 0)
	{
		g_flags.width = -g_flags.width;
		g_flags.moins = '-';
	}
	j++;
	return (j);
}

void	lenght_d(long i)
{
	long	j;

	j = 1;
	if (i < 0)
		j = 2;
	while (i >= 10 || i <= -10)
	{
		i = i / 10;
		j++;
	}
	g_flags.len = j;
}

void	lenght_x(unsigned long n)
{
	if (n <= 15)
		g_flags.len++;
	if (n > 15)
	{
		lenght_x(n / 16);
		lenght_x(n % 16);
	}
}
