/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startvm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:13:43 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/03 08:44:37 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void			ft_visu(t_vm *vm, int out, char *winner)
{
	char	buf[6];
	int		r;

	r = -1;
	if (vm->args.visu == 1)
	{
		if (out >= 0)
		{
			lseek(out, 0, SEEK_SET);
			r = read(out, buf, 5);
			while (r > 1)
			{
				lseek(out, 0, SEEK_SET);
				r = read(out, buf, 5);
			}
			ft_showramplayer(vm->ramplayer, vm, out, winner);
		}
	}
}

static void		ft_maxchecksandreset(t_vm *vm)
{
	if (vm->maxchecks >= MAX_CHECKS)
	{
		vm->cyclelimit -= CYCLE_DELTA;
		vm->maxchecks = 0;
		if (vm->args.verb == 1)
			ft_printffd(1, "cycle to die is now at %d\n", vm->cyclelimit);
	}
	vm->nblive = 0;
	vm->curcycle = 0;
}

static void		ft_checknblive(t_vm *vm, int out)
{
	if (vm->nblive == 0 || vm->cyclelimit < 0)
		ft_winner(vm, out);
	else if (vm->nblive >= NBR_LIVE)
	{
		vm->cyclelimit -= CYCLE_DELTA;
		vm->maxchecks = 0;
		if (vm->args.verb == 1)
			ft_printffd(1, "cycle to die is now at %d\n", vm->cyclelimit);
	}
	else
		vm->maxchecks++;
}

void			ft_startvm(t_vm *vm)
{
	int	out;

	out = -1;
	if (vm->args.visu == 1)
		out = open("OUTPUT.txt", O_CREAT | O_RDWR, S_IRWXU);
	while (vm->curcycle <= vm->cyclelimit || vm->cyclelimit <= 0)
	{
		if (vm->args.dump > 0 && vm->cycletotal == vm->args.dump)
		{
			ft_showram(vm->ram);
			exit(EXIT_SUCCESS);
		}
		ft_visu(vm, out, "");
		if (vm->curcycle == vm->cyclelimit || vm->cyclelimit <= 0)
		{
			ft_checkinlive(&(vm->processes), vm);
			ft_resetplayerinlive(&(vm->players));
			ft_checknblive(vm, out);
			ft_maxchecksandreset(vm);
		}
		else
			ft_nextcycle(vm);
	}
}
