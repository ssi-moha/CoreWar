/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:40:29 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/05/01 20:18:12 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_copyreg(t_process **new, t_process *proc)
{
	int i;
	int j;

	i = 0;
	while (i < REG_NUMBER)
	{
		j = 0;
		while (j < REG_SIZE)
		{
//			ft_printf("REG %d V %d\n", i + 1, proc->r[i][j]); 
			(*new)->r[i][j] = proc->r[i][j];
			j++;
		}
		i++;
	}
}

static void	ft_verbfork(int addr)
{
	ft_printf("\t\tat adress %d\n", addr);
}

int			ft_fork(t_process *proc, t_vm *vm)
{
	t_process	*new;
	t_player	*player;

	player = vm->players;
	while (player && player->number != proc->playernb)
		player = player->next;
	if ((new = new_process(player, vm)) == NULL)
		return (0);
	new->pc = proc->lastpc + (proc->par[0] % IDX_MOD);
	if (vm->args.verb == 1)
		ft_verbfork(proc->lastpc + (proc->par[0] % IDX_MOD));
	new->lastpc = new->pc;
	new->cycle = -1;
	new->inlive = proc->inlive;
	new->carry = proc->carry;
	ft_copyreg(&new, proc);
/*	int i;
	int j;

	i = 0;
	while (i < REG_NUMBER)
	{
		j = 0;
		while (j < REG_SIZE)
		{
			ft_printf("P%d REG %d V %d\n", new->id, i + 1, new->r[i][j]); 
			j++;
		}
		i++;
	}
*/
	return (1);
}
