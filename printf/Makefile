# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 19:27:45 by lfujimot          #+#    #+#              #
#    Updated: 2018/05/02 19:35:00 by emerabet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC = includes/ft_printf.h

SRCS = srcs/ft_atoi_sp.c \
	   srcs/ft_istype.c \
	   srcs/ft_forchar.c \
	   srcs/ft_forchar_uni.c \
	   srcs/ft_parse.c \
	   srcs/ft_manage_type.c \
	   srcs/ft_itoa_base_sp.c \
	   srcs/ft_ischarflag.c \
	   srcs/ft_isflag.c \
	   srcs/ft_printf.c \
	   srcs/ft_forstr.c \
	   srcs/ft_forstr_uni.c \
	   srcs/ft_ismod.c  \
	   srcs/ft_isnot_ten.c\
	   srcs/ft_fornb.c \
	   srcs/ft_intmaxt.c \
	   srcs/ft_uintmaxt.c \
	   srcs/ft_forpp.c \
	   srcs/ft_sizenb.c \
	   srcs/ft_flush.c \
	   srcs/ft_print_nb.c \
	   srcs/ft_max.c \
	   srcs/ft_isdigit.c \

.PHONY: all, clean, fclean, re

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(INC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
