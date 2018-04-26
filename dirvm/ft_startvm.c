/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startvm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:13:43 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/26 18:04:05 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_loadinstructions(t_vm *vm)
{
	t_process	*tmp;

	tmp = vm->processes;
	while (tmp)
	{
		if (tmp->cycle == 0)
			ft_loadnewinstr(tmp, vm);
		tmp->cycle--;
		tmp = tmp->next;
	}
}

void		ft_visu(t_vm *vm)
{
	int	fd;

	if (vm->args.visu == 1)
	{
		if ((fd = open("OUTPUT.txt", O_RDONLY)) < 0)
		{
			close(fd);
			ft_showramplayer(vm->ramplayer, vm);
		}
		else
		{
			while ((fd = open("OUTPUT.txt", O_RDONLY)) > 0)
			{
				if (fd < 0)
				{
					close(fd);
					ft_showramplayer(vm->ramplayer, vm);
				}
				close(fd);
			}
		}
	}
}

void		ft_maxchecksandreset(t_vm *vm)
{
	if (vm->maxchecks >= MAX_CHECKS)
	{
		vm->cyclelimit -= CYCLE_DELTA;
		vm->maxchecks = 0;
	}
	vm->nblive = 0;
	vm->curcycle = 0;
}

void		ft_checknblive(t_vm *vm)
{
	if (vm->nblive == 0 || vm->cyclelimit < CYCLE_DELTA)
		ft_winner(vm);
	else if (vm->nblive >= NBR_LIVE)
	{
		vm->cyclelimit -= CYCLE_DELTA;
		vm->maxchecks = 0;
	}
	else
		vm->maxchecks++;
}

void		ft_startvm(t_vm *vm)
{
	while (vm->curcycle <= vm->cyclelimit)
	{
		if (vm->args.dump > 0 && vm->cycletotal == vm->args.dump)
		{
			ft_showram(vm->ram);
			exit(2);
		}
		ft_visu(vm);
		if (vm->curcycle == vm->cyclelimit)
		{
			ft_checkinlive(&(vm->processes), vm);
			ft_resetplayerinlive(&(vm->players));
			ft_checknblive(vm);
			ft_maxchecksandreset(vm);
		}
		else
		{
			ft_loadinstructions(vm);
			vm->curcycle++;
			vm->cycletotal++;
		}
	}
}
