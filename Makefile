# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrachidi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 15:54:15 by mrachidi          #+#    #+#              #
#    Updated: 2020/03/04 17:47:23 by mrachidi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

file_srcs = convert_c.c convert_s.c convert_di.c convert_2di.c convert_u.c convert_2u.c convert_x.c convert_2x.c\
		   	convert_p.c convert_pr100.c flags.c flags_help.c ft_printf.c libft.c

file_objects = convert_c.o convert_s.o convert_di.o convert_2di.o convert_u.o convert_2u.o convert_x.o convert_2x.o\
			   convert_p.o convert_pr100.o flags.o flags_help.o ft_printf.o libft.o

all: $(NAME)

$(NAME):
		@gcc -Wextra -Wall -Werror -c $(file_srcs)
		@ar rc $(NAME) $(file_objects)
		@ranlib $(NAME)

clean:
		@/bin/rm -f $(file_objects)

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all

