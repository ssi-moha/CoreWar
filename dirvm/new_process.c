/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:16:41 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/26 18:01:52 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_initreg(t_process *process, unsigned int number)
{
	int	i;

	i = 0;
	process->playernb = number;
	while (i < REG_NUMBER)
		ft_memset(process->r[i++], 0, REG_SIZE);
	i = REG_SIZE - 1;
	while (i >= 0)
	{
		process->r[0][i] = number % 256;
		number /= 256;
		i--;
	}
	ft_memset(process->partype, 0, 3);
	ft_setint(process->par, 0, 3);
}

t_process	*new_process(t_player *player, t_vm *vm)
{
	t_process	*tmp;

	tmp = NULL;
	if (!(tmp = (t_process*)malloc(sizeof(t_process))))
		return (0);
	ft_initreg(tmp, player->number);
	tmp->pc = player->startpos;
	tmp->lastpc = player->startpos;
	tmp->cycle = 0;
	tmp->inlive = 0;
	tmp->carry = 0;
	tmp->id = ++(vm->totalprocess);
	tmp->num = player->num;
	tmp->cmd = DEFAULT;
	tmp->next = NULL;
	if (!vm->processes)
		vm->processes = tmp;
	else
	{
		tmp->next = vm->processes;
		vm->processes = tmp;
	}
	return (tmp);
}
