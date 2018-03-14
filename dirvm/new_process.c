/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:16:41 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/14 14:18:18 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_initreg(t_process *process, unsigned int number)
{
	int	i;

	printf("**************************************************\n");
	printf("%d %u\n", number, number);
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
}

t_process	*new_process(t_player *player, t_process **prev, t_vm *vm)
{
	t_process	*tmp;
	t_process	*tmp2;
	static int	i;

	tmp = NULL;
	tmp2 = *prev;
	if (!(tmp = (t_process*)malloc(sizeof(t_process))))
		return (0);
	ft_initreg(tmp, player->number);
	tmp->pc = player->startpos;
	tmp->cycle = 0;
	tmp->inlive = 0;
	tmp->carry = 0; //check
	tmp->id = ++(vm->totalprocess); 
	tmp->cmd = DEFAULT;
	ft_memset(tmp->partype, 0, 3);
	ft_setint(tmp->par, 0, 3);
	tmp->next = NULL;
	if (!*prev)
		*prev = tmp;
	else
	{
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
	}
	return (tmp);
}

void	free_process(t_process **proc)
{
	t_process *tmp;

	if (!*proc)
		return ;
	tmp = *proc;
	if (tmp->next)
		tmp = tmp->next;
	while (*proc)
	{
		tmp = tmp->next;
		free(*proc);
		*proc = tmp;
	}
}
