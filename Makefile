# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/03 17:07:49 by lfujimot          #+#    #+#              #
#    Updated: 2018/05/18 11:33:30 by lfujimot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm

.PHONY: all, clean, fclean, re

CORH = includes/ft_corewar.h includes/op.h

SRCSASM = dirasm/asm.c \
		  dirasm/free_par.c \
		  dirasm/free_lab.c \
		  dirasm/new_par.c \
		  dirasm/new_instr.c \
		  dirasm/new_label.c \
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
		  dirasm/ft_labonly.c\
		  dirasm/cnt_char.c\
		  dirasm/join_lines.c\
		  dirvm/ft_check_filename.c\
		  dirasm/ft_type_value.c\
		  dirasm/ft_checkpartype.c\
		  dirasm/ft_parseasm.c\
		  dirasm/ft_pushline.c\
		  dirasm/ft_check_error.c\

OBJSASM = $(SRCSASM:.c=.o)

VM = corewar

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
		dirvm/ft_add.c \
		dirvm/ft_sub.c \
		dirvm/ft_or.c \
		dirvm/ft_xor.c \
		dirvm/ft_sti.c \
		dirvm/ft_aff.c \
		dirvm/ft_zjmp.c \
		dirvm/ft_ld.c \
		dirvm/ft_fork.c \
		dirvm/ft_lfork.c \
		dirvm/ft_lld.c \
		dirvm/ft_ldi.c \
		dirvm/ft_lldi.c \
		dirvm/ft_st.c \
		dirvm/ft_setcomment.c\
		dirvm/ft_getparvalue.c\
		dirvm/ft_writeinreg.c\
		dirvm/ft_writeinram.c\
		dirvm/ft_readinram.c\
		dirvm/ft_resetplayerinlive.c\
		dirvm/ft_winner.c\
		dirvm/ft_uchar_toint.c\
		dirvm/ft_check_champion.c\
		dirvm/ft_haslive.c\
		dirvm/ft_nextcycle.c\

OBJSVM = $(SRCSVM:.c=.o)

LIBFT = libft

LFT = libft/libft.a

PRINTFFD = printffd

PFFD = printffd/libftprintffd.a

GNL = gnl/get_next_line.c

GNLO = $(GNL:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all : $(ASM) $(VM)

$(ASM): $(OBJSASM) $(CORH) $(GNLO)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(PRINTFFD)
	gcc $(OBJSASM) $(GNLO) $(LFT) $(PFFD) -o $(ASM)

$(VM): $(OBJSVM) $(CORH) $(GNLO)
	gcc $(OBJSVM) $(GNLO) $(LFT) $(PFFD) -o $(VM)

clean: $(LIBFT) $(PRINTF) $(PRINTFFD)
	rm -f $(OBJSASM) $(OBJSVM)
	rm -f $(GNLO)
	make -C "$(LIBFT)" clean
	make -C "$(PRINTFFD)" clean

fclean: clean $(LIBFT) $(PRINTFFD)
	rm -f $(ASM) $(VM)
	make -C "$(LIBFT)" fclean
	make -C "$(PRINTFFD)" fclean

re: fclean all $(LIBFT) $(PRINTFFD)
