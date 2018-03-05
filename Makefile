# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 17:07:49 by lfujimot          #+#    #+#              #
#    Updated: 2018/03/05 14:41:50 by emerabet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm

SRCSASM = dirasm/asm.c \
		  dirasm/free_par.c \
		  dirasm/new_par.c \
		  dirasm/new_instr.c \
		  dirasm/free_instr.c \
		  dirasm/ft_parselabel.c \
		  dirasm/ft_parseinstr.c \
		  dirasm/ft_parseparams.c \
		  dirasm/op.c \
		  dirasm/ft_checkparams.c \
		  dirasm/ft_skip_com_and_blank.c \
		  dirasm/ft_findcmd.c \
		  dirasm/ft_test.c \
		  dirasm/ft_isincharset.c

OBJSASM = $(SRCSASM:.c=.o)

LIBFT = libft

LFT = libft/libft.a

PRINTF = printf

PF = printf/libftprintf.a

GNL = gnl/get_next_line.c

GNLO = get_next_line.o

#CFLAGS = -Wall -Werror -Wextra

all : $(ASM)

$(ASM): $(OBJSASM)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(PRINTF)
	gcc -c $(GNL) $(LFT)
	gcc $(OBJSASM) $(LFT) $(PF) -o $(ASM) $(GNLO)

clean: $(LIBFT) $(PRINTF)
	rm -f $(OBJSASM)
	rm -f $(GNLO)
	make -C "$(LIBFT)" clean
	make -C "$(PRINTF)" clean

fclean: clean $(LIBFT) $(PRINTF)
	rm -f $(ASM)
	make -C "$(LIBFT)" fclean
	make -C "$(PRINTF)" fclean

re: fclean all $(LIBFT) $(PRINTF)
