/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 06:46:51 by mrachidi          #+#    #+#             */
/*   Updated: 2020/03/04 17:53:56 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialisation(void)
{
	g_flags.width = 0;
	g_flags.precision = 0;
	g_flags.zero = 0;
	g_flags.len = 0;
	g_flags.point = 0;
	g_flags.moins = 0;
	g_flags.etoile1 = 0;
	g_flags.etoile2 = 0;
}

int		remplissage1(void)
{
	int j;

	j = 0;
	while (*(g_flags.fstr + j) == '-')
	{
		g_flags.moins = '-';
		j++;
	}
	if (*(g_flags.fstr + j) == '0')
	{
		g_flags.zero = '0';
		j++;
	}
	return (j);
}

int		remplissage2(int i)
{
	char	*num;
	int		j;
	int		h;

	j = 0;
	h = i;
	while (*(g_flags.fstr + i) >= '0' && *(g_flags.fstr + i) <= '9')
	{
		i++;
		j++;
	}
	num = malloc(j + 1);
	j = remplissage_num(num, h);
	free(num);
	num = NULL;
	return (j);
}

void	remplir(va_list arg)
{
	int	j;

	j = remplissage1();
	if (*(g_flags.fstr + j) == '*')
	{
		g_flags.etoile1 = '*';
		j = remplissage3(j, arg);
	}
	else
		j = remplissage2(j);
	if (*(g_flags.fstr + j) == '.')
	{
		g_flags.point = '.';
		j++;
		if (*(g_flags.fstr + j) == '*')
		{
			g_flags.etoile2 = '*';
			g_flags.precision = va_arg(arg, int);
			j++;
		}
		else
			j = remplissage2(j);
	}
}

int		remplissage_num(char *num, int h)
{
	int	k;
	int	j;

	k = h - 1;
	j = 0;
	while (*(g_flags.fstr + h) >= '0' && *(g_flags.fstr + h) <= '9')
	{
		*(num + j) = *(g_flags.fstr + h);
		h++;
		j++;
	}
	*(num + j) = '\0';
	if (*(g_flags.fstr + k) == '.')
		g_flags.precision = ft_atoi(num);
	else
		g_flags.width = ft_atoi(num);
	return (h);
}
