/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:03:17 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/05/02 19:00:47 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_verbzjmp(int c, t_process *proc)
{
	if (c == 1)
		ft_printf("\t\t zjump OK PC at %d\n", proc->pc);
	else
		ft_printf("\t\t zjump KO\n");
}

int			ft_zjmp(t_process *proc, t_vm *vm)
{
	int value;
	int	p;

	value = 0;
	if (proc->carry == 1)
	{
		value = ft_getparvalue(proc, vm, 0, MEM_SIZE);
		p = proc->pc - 3 + value;
		if (p < 0)
			proc->pc = p + MEM_SIZE - 1;
		else
			proc->pc = p;
	}
	if (vm->args.verb == 1)
		ft_verbzjmp(proc->carry, proc);
	return (1);
}
