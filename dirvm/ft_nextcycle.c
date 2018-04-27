/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextcycle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 17:26:32 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/27 17:29:58 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_loadinstructions(t_vm *vm)
{
	t_process	*tmp;

	tmp = vm->processes;
	while (tmp)
	{
		if (tmp->cycle <= 0)
			ft_loadnewinstr(tmp, vm);
		tmp->cycle--;
		tmp = tmp->next;
	}
}

void		ft_nextcycle(t_vm *vm)
{
	ft_loadinstructions(vm);
	vm->curcycle++;
	vm->cycletotal++;
}
