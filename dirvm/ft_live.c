/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:39:09 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/20 15:49:07 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static int	ft_correctplayer(t_player **p, int id)
{
	t_player	*tmp;

	tmp = *p;
	while (tmp)
	{
		if (tmp->id == id)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_live(t_process *proc, t_vm *vm)
{
	t_player	*tmp;
	t_process	*tmp2;

	printf("\x1b[31mLIVE DONE BY %d\n\x1b[0m", proc->id);
	if (vm == 0 || proc == 0)
		return (0);
	tmp = vm->players;
	tmp2 = vm->processes;
	if (tmp == 0 || tmp2 == 0)
		return (0);
	while (tmp && tmp->number != proc->par[0])
		tmp = tmp->next;
	if (tmp == NULL)
		ft_printf("pas de player trouve avec cet id %d on continue\n",
					proc->par[0]);
	else
	{
		ft_printf("un processus dit que le joueur %d(%s) est en vie",
				tmp->number, tmp->header.prog_name);
		proc->inlive = 1;
		tmp->inlive = 1;
		vm->nblive++;
		if (ft_correctplayer(&(vm->players), proc->par[0]) == 1)
			vm->lastlive = proc->par[0];
		return (1);
	}
	return (0);
}
