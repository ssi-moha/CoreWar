/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startvm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:13:43 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/11 17:07:27 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_loadinstructions(t_vm *vm)
{
	t_process	*tmp;

	tmp = vm->processes;
	while (tmp)
	{
		if (tmp->cycle == 0)
			ft_loadnewinstr(tmp, vm);
		tmp = tmp->next;
	}
}

void	ft_startvm(t_vm *vm)
{
	printf("LIMIT %d\n", vm->cyclelimit);
	printf("CUR %d\n", vm->curcycle);
//	while (vm->curcycle < vm->cyclelimit)
//	{
		ft_loadinstructions(vm);
//		vm->curcycle++;
//	}
}
