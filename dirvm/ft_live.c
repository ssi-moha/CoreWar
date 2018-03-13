/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:39:09 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/13 13:38:54 by lfujimot         ###   ########.fr       */
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
	ft_printf("un processus dit que le joueur %d(%s) est en vie", tmp->number, tmp->header.prog_name);
	while (tmp2 && tmp2->playernb != proc->par[0])
		tmp = tmp->next;
	tmp2->inlive = 1;
	tmp->inlive = 1;
	vm->nblive++;
	return (1);
}
