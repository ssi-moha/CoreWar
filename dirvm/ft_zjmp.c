/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:03:17 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/15 17:59:28 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int	ft_zjmp(t_process *proc, t_vm *vm)
{
	int value;

	value = 0;
	if (proc->carry == 1)
	{
		value = ft_getparvalue(proc, vm, 0, MEM_SIZE);
		proc->pc = (proc->pc + value - 3) % IDX_MOD;
	}
	return (1);
}
