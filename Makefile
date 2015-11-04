# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/08 18:45:01 by plisieck          #+#    #+#              #
#    Updated: 2015/02/08 18:45:19 by plisieck         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
GCCW = gcc -Wall -Wextra -Werror
SRC  = ft_strlen.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putendl.c ft_itoa.c \
	   ft_ltoa.c ft_wstrdup.c ft_wstrlen.c ft_convertion_base.c ft_strrjoin.c  \
	   ft_strjoin.c ft_strcat.c ft_wputchar.c ft_strcpy.c ft_strdup.c          \
	   ft_wputstr.c ft_itoa.c ft_strnew.c ft_memalloc.c ft_atoi.c ft_strcmp.c  \
	   ft_isspace.c ft_wstrjoin.c ft_strsub.c ft_printf.c ft_printf1.c         \
	   ft_printf2.c ft_printf3.c ft_printf4.c ft_printf5.c ft_printf6.c        \
	   ft_printf7.c ft_printf8.c ft_printf9.c ft_printf10.c ft_printf11.c      \
	   ft_printf12.c ft_printf13.c

OBJECT = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@echo  "\033[1;32m"
	$(GCCW) -c $(SRC)
	ar rc $(NAME) $(OBJECT)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
