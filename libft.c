/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:07:32 by mrachidi          #+#    #+#             */
/*   Updated: 2020/03/04 17:46:25 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(char *s)
{
	char	*p;
	int		len;
	int		i;

	len = 0;
	if (s == 0)
		return (0);
	while (s[len] != '\0')
		len++;
	if (!(p = malloc(len + 1)))
		return (0);
	i = len;
	g_flags.len = len;
	len = 0;
	while (len < i)
	{
		p[len] = s[len];
		len++;
	}
	p[len] = '\0';
	return (p);
}

int     ft_atoi(char *str)
{
	int			i;
	long int	nb;
	int			sign;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + str[i] - '0';
		if (nb * sign < -2147483648)
			return (0);
		if (nb * sign > 2147483647)
			return (-1);
		i++;
	}
	return (nb * sign);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putnbr(-2147);
		ft_putnbr(483648);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-(n));
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
	}
	if (n > 9)
	{
		ft_putnbr((n / 10));
		ft_putnbr((n % 10));
	}
}

void	ft_putunbr(unsigned int n)
{
	if (n <= 9)
	{
		ft_putchar(n + '0');
	}
	if (n > 9)
	{
		ft_putunbr((n / 10));
		ft_putunbr((n % 10));
	}
}

void	ft_puthex(unsigned long n, int j)
{
	int		i;

	i = 0;
	if (j == 2)
		i = 32;
	if (n <= 9)
		ft_putchar(n + '0');
	else if (n == 10)
		ft_putchar('A' + i);
	else if (n == 11)
		ft_putchar('B' + i);
	else if (n == 12)
		ft_putchar('C' + i);
	else if (n == 13)
		ft_putchar('D' + i);
	else if (n == 14)
		ft_putchar('E' + i);
	else if (n == 15)
		ft_putchar('F' + i);
	if (n > 15)
	{
		ft_puthex(n / 16, j);
		ft_puthex(n % 16, j);
	}
}
