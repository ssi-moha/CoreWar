/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:39:09 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/14 14:46:30 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int	ft_live(t_process *proc, t_vm *vm)
{
	t_player *tmp;
	t_process *tmp2;

	tmp = vm->players;
	tmp2 = vm->processes;
	while (tmp && tmp->number != proc->par[0])
		tmp = tmp->next;
	if (tmp == NULL)
		fprintf(stderr, "pas de player trouve\n");
	else
	{
		ft_printf("un processus dit que le joueur %d(%s) est en vie", tmp->number, tmp->header.prog_name);
		proc->inlive = 1;
		tmp->inlive = 1;
		vm->nblive++;
		return (1);
	}
	return (0);
}
