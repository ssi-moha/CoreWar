/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:40:29 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/04/24 17:16:52 by lfujimot         ###   ########.fr       */
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

int			ft_fork(t_process *proc, t_vm *vm)
{
	t_process	*new;
	t_player	*player;
	fprintf(stderr, "FORK");
//	printf("\x1b[33mFORK %d\n\x1b[0m", proc->id);
	player = vm->players;
	while (player && player->number != proc->playernb)
		player = player->next;
	fprintf(stderr, "FORK2");
	if ((new = new_process(player, &proc, vm)) == NULL)
		return (0);
	fprintf(stderr, "FORK3");
	new->pc = proc->pc + (proc->par[0] % IDX_MOD);
	new->cycle = 0;
	new->inlive = proc->inlive;
	new->carry = proc->carry;
	ft_copyreg(new, proc);
	return (1);
}
