/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:03:17 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/04/26 12:25:28 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_verbzjmp(int c)
{
	if (c == 1)
		ft_printf("\t\t zjump OK\n");
	else
		ft_printf("\t\t zjump KO\n");
}

int			ft_zjmp(t_process *proc, t_vm *vm)
{
	int value;

	value = 0;
	if (proc->carry == 1)
	{
		value = ft_getparvalue(proc, vm, 0, MEM_SIZE);
		proc->pc = proc->pc - 3 + value % IDX_MOD;
	}
	if (vm->args.verb == 1)
		ft_verbzjmp(proc->carry);
	return (1);
}
