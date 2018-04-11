/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:03:17 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/04/11 13:44:25 by lfujimot         ###   ########.fr       */
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
		proc->pc = proc->pc - 3 + value % IDX_MOD;
		fprintf(stderr, "FORK AT %d\n", proc->pc);
	}
	return (1);
}
