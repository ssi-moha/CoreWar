/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:44:29 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/11 13:53:06 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void	ft_showram(unsigned char *ram)
{
	int				i;
	int				n;

	i = 0;
	n = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%3.2x", ram[i]);
		if (n == 63)
		{
			ft_printf("\n");
			n = -1;
		}
		n++;
		i++;
	}
}

void	ft_showramplayer(unsigned char *ram, t_vm *vm)
{
	int				i;
	int				n;
	int				out;
	t_player		*p;
	t_process		*proc;

	i = 0;
	n = 0;
	out = open("OUTPUT.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	p = vm->players;
	while (p)
	{
		ft_printffd(out, "p:%d;nbl:%d;nm:%s;", p->number, p->nblive, p->header.prog_name);	
		p = p->next;
	}
		ft_printffd(out, "\nc:%d;ctd:%d;cd:%d;nbl:%d;pc:%d;max:%d;\n", vm->cycletotal, vm->cyclelimit, CYCLE_DELTA, NBR_LIVE, vm->totalprocess, MAX_CHECKS);
	proc = vm->processes;
	while (proc)
	{
		ft_printffd(out, "pos:%d;", proc->pc);
		proc = proc->next;
	}
	write(out, "\n", 1);
	while (i < MEM_SIZE)
	{
		if (ram[i] == '\0')
			write(out, "x", 1);
		else
			write(out, &ram[i], 1);
		if (n == 63)
		{
			write(out, "\n", 1);
			n = -1;
		}
		n++;
		i++;
	}

	write(out, "\n", 1);
	close(out);
}
