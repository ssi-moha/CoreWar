/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:40:29 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/13 13:01:18 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void	ft_fork(t_process *proc, t_vm *vm)
{
	t_process *new;
	t_player *player;

	player = vm->players;
	while (player && player->number != proc->playernb)
			player = player->next;
	if ((new = new_process(player, &proc, vm)) == NULL)
		return ;
	new->pc = proc->pc + (proc->par[0] % IDX_MOD);
	new->cycle = proc->cycle;
	new->inlive = proc->inlive;
	new->carry = proc->carry;
	new->cmd = proc->cmd;
}
