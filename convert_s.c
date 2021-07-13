/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 03:30:44 by mrachidi          #+#    #+#             */
/*   Updated: 2020/03/04 17:43:03 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_s(va_list arg)
{
	char	*s;

	ft_initialisation();
	remplir(arg);
	s = ft_strdup(va_arg(arg, char *));
	if (s == 0)
		s = ft_strdup("(null)");
	if (g_flags.point != 0)
	{
		if (g_flags.moins != 0)
			condition_s1(s);
		else
			condition_s2(s);
	}
	else
	{
		if (g_flags.moins != 0)
			condition_s3(s);
		else
			condition_s4(s);
	}
	free(s);
	s = NULL;
	return (1);
}

void	condition_s1(char *s)
{
	int		i;
	int		j;

	i = 0;
	if ((g_flags.precision <= g_flags.len) && (g_flags.precision >= 0))
		j = g_flags.precision;
	else
		j = g_flags.len;
	while (s[i] != '\0' && i < j)
	{
		ft_putchar(s[i++]);
		g_ret++;
	}
	i = 0;
	while (i < (g_flags.width - j))
	{
		ft_putchar(' ');
		g_ret++;
		i++;
	}
}

void	condition_s2(char *s)
{
	int		i;
	int		j;

	i = 0;
	if ((g_flags.precision <= g_flags.len) && (g_flags.precision >= 0))
		j = g_flags.precision;
	else
		j = g_flags.len;
	while (i < (g_flags.width - j))
	{
		ft_putchar(' ');
		g_ret++;
		i++;
	}
	i = 0;
	while (s[i] != '\0' && i < j)
	{
		ft_putchar(s[i++]);
		g_ret++;
	}
}

void	condition_s3(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i++]);
		g_ret++;
	}
	i = 0;
	while (i++ < (g_flags.width - g_flags.len))
	{
		ft_putchar(' ');
		g_ret++;
	}
}

void	condition_s4(char *s)
{
	int		i;

	i = 0;
	while (i++ < (g_flags.width - g_flags.len))
	{
		ft_putchar(' ');
		g_ret++;
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i++]);
		g_ret++;
	}
}
