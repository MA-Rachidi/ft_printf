/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 01:47:31 by mrachidi          #+#    #+#             */
/*   Updated: 2020/03/04 17:53:05 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

int		ft_printf(const char *str, ...)
{
	va_list	arg;

	g_ret = 0;
	g_count = 0;
	va_start(arg, str);
	while (*(str + g_count) != '\0')
	{
		if (*(str + g_count) == '%')
		{
			if (ft_convert((char *)str, arg) == 0)
				return (-1);
		}
		else
		{
			ft_putchar(*(str + g_count));
			g_ret++;
		}
		g_count++;
	}
	va_end(arg);
	return (g_ret);
}

int		ft_convert(char *str, va_list arg)
{
	int j;
	int	i;

	j = 1 + g_count + check(str);
	if (*(str + j) == 'i' || *(str + j) == 'd')
		i = convert_di(arg);
	else if (*(str + j) == 'c')
		i = convert_c(arg);
	else if (*(str + j) == 's')
		i = convert_s(arg);
	else if (*(str + j) == 'x')
		i = convert_x(arg, 2);
	else if (*(str + j) == 'X')
		i = convert_x(arg, 1);
	else if (*(str + j) == 'p')
		i = convert_p(arg, 2);
	else if (*(str + j) == 'u')
		i = convert_u(arg);
	else if (*(str + j) == '%')
		i = convert_pr100(arg);
	else
		i = 1;
	g_count++;
	return (i);
}

int		check(char *str)
{
	int j;
	int i;

	i = 0;
	j = g_count + 1;
	while ((*(str + j) <= 57 && *(str + j) >= 48) || *(str + j) == '-' ||
			*(str + j) == '.' || *(str + j) == '*')
	{
		i++;
		j++;
	}
	j = g_count + 1;
	g_flags.fstr = malloc(i + 1);
	i = 0;
	while ((*(str + j) <= 57 && *(str + j) >= 48) || *(str + j) == '-' ||
			*(str + j) == '.' || *(str + j) == '*')
	{
		*(g_flags.fstr + i) = *(str + j);
		i++;
		j++;
	}
	*(g_flags.fstr + i) = '\0';
	g_count = g_count + i;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
