# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 17:07:49 by lfujimot          #+#    #+#              #
#    Updated: 2018/03/14 17:15:23 by lfujimot         ###   ########.fr        #
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
		  dirasm/check_format.c \
		  dirasm/ft_isincharset.c\
		  dirasm/ft_convertheader.c\
		  dirasm/ft_converttohex.c\
		  dirasm/ft_printhex.c\
		  dirasm/prog_size.c\
		  dirasm/count_label.c\
		  dirasm/ft_printsizepar.c\
		  dirasm/ft_printdirl.c\
		  dirasm/cpy_head.c\
		  dirasm/ft_printdir.c\
		  dirasm/error_mess.c\
		  dirasm/ft_printindl.c\
		  dirasm/make_pos.c\
		  dirvm/ft_check_filename.c\

OBJSASM = $(SRCSASM:.c=.o)

VM = vm

SRCSVM = dirvm/vm.c \
		dirvm/ft_openfile.c \
		dirvm/ft_check_filename.c \
		dirvm/ft_checkmagic.c \
		dirvm/ft_checkprogsize.c \
		dirvm/ft_loadinram.c \
		dirasm/error_mess.c\
		dirvm/new_player.c\
		dirvm/ft_setname.c\
		dirvm/ft_showram.c\
		dirvm/new_process.c\
		dirvm/ft_startvm.c \
		dirvm/ft_loadnewinstr.c \
		dirvm/op.c \
		dirvm/ft_setint.c \
		dirvm/ft_parse_arg.c \
		dirvm/ft_checkinlive.c \
		dirvm/rm_proc.c \
		dirvm/func_tab.c \
		dirvm/ft_live.c \
		dirvm/ft_and.c \
		dirvm/ft_or.c \
		dirvm/ft_xor.c \
		dirvm/ft_sti.c \
		dirvm/ft_aff.c \
		dirvm/ft_ld.c \
		dirvm/ft_ldi.c \
		dirvm/ft_st.c \
		dirvm/ft_setcomment.c\
		dirvm/ft_getparvalue.c\
		dirvm/ft_writeinreg.c\
		dirvm/ft_writeinram.c\
		dirvm/ft_readinram.c\
		dirvm/ft_uchar_toint.c\

OBJSVM = $(SRCSVM:.c=.o)

LIBFT = libft

LFT = libft/libft.a

PRINTF = printf

PF = printf/libftprintf.a

GNL = gnl/get_next_line.c

GNLO = get_next_line.o

#CFLAGS = -Wall -Werror -Wextra

all : $(ASM) $(VM)

$(ASM): $(OBJSASM)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(PRINTF)
	gcc -c $(GNL) $(LFT)
	gcc $(OBJSASM) $(LFT) $(PF) -o $(ASM) $(GNLO)

$(VM): $(OBJSVM)
	gcc $(OBJSVM) $(LFT) $(PF) -o $(VM)

clean: $(LIBFT) $(PRINTF)
	rm -f $(OBJSASM) $(OBJSVM)
	rm -f $(GNLO)
	make -C "$(LIBFT)" clean
	make -C "$(PRINTF)" clean

fclean: clean $(LIBFT) $(PRINTF)
	rm -f $(ASM) $(VM)
	make -C "$(LIBFT)" fclean
	make -C "$(PRINTF)" fclean

re: fclean all $(LIBFT) $(PRINTF)
