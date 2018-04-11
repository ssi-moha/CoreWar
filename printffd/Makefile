# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 19:27:45 by lfujimot          #+#    #+#              #
#    Updated: 2018/04/10 17:40:23 by lfujimot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintffd.a

SRCS = srcs/ft_atoi_sp.c \
	   srcs/ft_istype.c \
	   srcs/ft_forchar.c \
	   srcs/ft_forchar_uni.c \
	   srcs/ft_parse.c \
	   srcs/ft_manage_type.c \
	   srcs/ft_itoa_base_sp.c \
	   srcs/ft_ischarflag.c \
	   srcs/ft_isflag.c \
	   srcs/ft_printffd.c \
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

OBJS = ft_atoi_sp.o \
	   ft_istype.o \
	   ft_forchar.o \
	   ft_forchar_uni.o \
	   ft_parse.o \
	   ft_manage_type.o \
	   ft_itoa_base_sp.o \
	   ft_ischarflag.o \
	   ft_isflag.o \
	   ft_printffd.o \
	   ft_forstr.o \
	   ft_forstr_uni.o \
	   ft_ismod.o  \
	   ft_isnot_ten.o\
	   ft_fornb.o \
	   ft_intmaxt.o \
	   ft_uintmaxt.o \
	   ft_forpp.o \
	   ft_sizenb.o \
	   ft_flush.o \
	   ft_print_nb.o \
	   ft_max.o \
	   ft_isdigit.o \

all: $(NAME)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
