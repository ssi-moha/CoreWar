/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:44:29 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/03 08:44:13 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void		ft_showram(unsigned char *ram)
{
	int				i;
	int				n;

	i = 0;
	n = 0;
	while (i < MEM_SIZE)
	{
		ft_printffd(1, "%3.2x", ram[i]);
		if (n == 31)
		{
			ft_printffd(1, "\n");
			n = -1;
		}
		n++;
		i++;
	}
}

static void	ft_tolow(t_vm *vm)
{
	int i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (vm->ramplayer[i] >= 'A' && vm->ramplayer[i] <= 'Z')
			vm->ramplayer[i] = vm->ramplayer[i] + 32;
		i++;
	}
}

static void	ft_printp(t_vm *vm, int out)
{
	t_player	*p;
	t_process	*proc;

	p = vm->players;
	while (p)
	{
		ft_printffd(out, "p:%d;nbl:%d;nm:%s;", p->number,
				p->nblive, p->header.prog_name);
		p = p->next;
	}
	ft_printffd(out, "\nc:%d;ctd:%d;cd:%d;nbl:%d;pc:%d;max:%d;\n",
			vm->cycletotal, vm->cyclelimit, CYCLE_DELTA, NBR_LIVE,
			vm->totalprocess, MAX_CHECKS);
	proc = vm->processes;
	while (proc)
	{
		ft_printffd(out, "pos:%d;", proc->pc);
		proc = proc->next;
	}
}

void		ft_showramplayer(unsigned char *ram, t_vm *vm,
			int out, char *winner)
{
	int				i;
	int				n;

	i = -1;
	n = 0;
	lseek(out, 0, SEEK_SET);
	ft_printffd(out, "winner:%s\n", winner);
	ft_printp(vm, out);
	write(out, "\n", 1);
	while (++i < MEM_SIZE)
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
	}
	ft_tolow(vm);
	write(out, "\n", 1);
}
