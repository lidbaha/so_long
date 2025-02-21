# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lidbaha <lidbaha@student.42lehavre.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/21 14:10:31 by lidbaha           #+#    #+#              #
#    Updated: 2024/11/29 11:59:31 by lidbaha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c \
		ft_putchar.c \
		ft_putnbr_hexa.c \
		ft_putnbr_unsigned.c \
		ft_putnbr.c \
		ft_putptr.c \
		ft_putstr.c \

OBJS = ${SRCS:.c=.o}

CC = cc

FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

all: ${NAME}

${NAME}: ${OBJS}
		ar -crs ${NAME} ${OBJS}

%.o: %.c
	${CC} ${FLAGS} -c $< -o $@

clean :
			rm -f ${OBJS}

fclean : clean
			rm -f ${NAME}

re: fclean all