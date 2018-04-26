/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:06:47 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/26 09:50:13 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_copyreg(t_process *new, t_process *proc)
{
	int i;
	int j;

	i = 0;
	while (i < REG_NUMBER)
	{
		j = 0;
		while (j < REG_SIZE)
		{
			new->r[i][j] = proc->r[i][j];
			j++;
		}
		i++;
	}
}

int			ft_lfork(t_process *proc, t_vm *vm)
{
	t_process	*new;
	t_player	*player;

	player = vm->players;
	while (player && player->number != proc->playernb)
		player = player->next;
	if ((new = new_process(player, &proc, vm)) == NULL)
		return (0);
	new->pc = proc->lastpc + proc->par[0];
	new->lastpc = new->pc;
	new->cycle = 0;
	new->inlive = proc->inlive;
	new->carry = proc->carry;
	ft_copyreg(new, proc);
	return (1);
}
