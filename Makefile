# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 17:07:49 by lfujimot          #+#    #+#              #
#    Updated: 2018/03/03 17:24:56 by lfujimot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm

SRCSASM =

OBJSASM = $(SRCSASM:.c=.o)

LIBFT = libft

LFT = libft/libft.a

PRINTF = printf

PF = printf/libftprintf.a

GNL = gnl/get_next_line.c

GNLO = $(GNL:.c=.o)

#CFLAGS = -Wall -Werror -Wextra

all : $(ASM)

$(ASM): $(OBJSASM)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(PRINTF)
	gcc $(GNL) $(LFT)
	gcc $(OBJSASM) $(LFT) $(PF) -o $(NAME)

clean: $(LIBFT) $(PRINTF)
	rm -f $(OBJSASM)
	make -C "$(LIBFT)" clean
	make -C "$(PRINTF)" clean

fclean: clean $(LIBFT) $(PRINTF)
	rm -f $(ASM)
	make -C "$(LIBFT)" fclean
	make -C "$(PRINTF)" fclean

re: fclean all $(LIBFT) $(PRINTF)
