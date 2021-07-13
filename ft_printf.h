/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 02:09:29 by mrachidi          #+#    #+#             */
/*   Updated: 2020/03/04 18:02:03 by mrachidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int			width;
	int			precision;
	char		zero;
	int			len;
	char		point;
	char		moins;
	char		etoile1;
	char		etoile2;
	char		*fstr;
}				t_flags;

t_flags			g_flags;
int				g_ret;
int				g_count;

int				ft_printf(const char *str, ...);
int				check(char *str);
int				ft_convert(char *str, va_list arg);
void			ft_putchar(char c);
void			ft_initialisation();
int				remplissage1();
int				remplissage2(int i);
int				remplissage3(int i, va_list arg);
void			remplir(va_list arg);
int				remplissage_num(char *num, int h);
void			lenght_d(long i);
void			lenght_x(unsigned long i);
int				ft_atoi(char *str);
char			*ft_strdup(char *s);
void			ft_putnbr(int n);
void			ft_putunbr(unsigned int n);
void			ft_puthex(unsigned long n, int j);
int				convert_c(va_list arg);
int				help_c(char s);
int				convert_s(va_list arg);
void			condition_s1(char *s);
void			condition_s2(char *s);
void			condition_s3(char *s);
void			condition_s4(char *s);
int				convert_di(va_list arg);
void			condition_d1(int h);
void			condition_d2(int h);
void			condition_d3(int i);
void			condition_d4(int i);
void			condition_d5();
void			condition_d6(int h);
void			condition_d7(int h);
void			condition_d8(int h);
void			condition_d9(int h);
int				convert_u(va_list arg);
void			condition_u1(unsigned int h);
void			condition_u2(unsigned int h);
void			condition_u3(unsigned int i);
void			condition_u4(unsigned int i);
void			condition_u5();
void			condition_u6(unsigned int h);
void			condition_u7(unsigned int h);
void			condition_u8(unsigned int h);
void			condition_u9(unsigned int h);
int				convert_x(va_list arg, int j);
void			condition_x1(unsigned int h, int k);
void			condition_x2(unsigned int h, int k);
void			condition_x3(unsigned int h, int k);
void			condition_x4(unsigned int h, int k);
void			condition_x5();
void			condition_x6(unsigned int h, int k);
void			condition_x7(unsigned int h, int k);
void			condition_x8(unsigned int h, int k);
void			condition_x9(unsigned int h, int k);
int				convert_p(va_list arg, int j);
void			condition_p1(unsigned long i, int j);
void			condition_p2(unsigned long i, int j);
int				convert_pr100(va_list arg);
void			condition_pr101();
void			condition_pr102();

#endif
