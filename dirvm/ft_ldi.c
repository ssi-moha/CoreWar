/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:40:27 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/03 08:47:05 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_verbldi(int a, int b, int c, int pc)
{
	ft_printffd(1, "\t\tload from %d + %d = %d (%d at pc %d)\n",
			a, b, a + b, c, pc);
}

int			ft_ldi(t_process *proc, t_vm *vm)
{
	int a;
	int b;
	int c;
	int pc;

	a = proc->par[0];
	b = proc->par[1];
	if ((a + b) < 0)
		pc = proc->pc + a + b - 4;
	else
		pc = proc->pc + ((a + b) % IDX_MOD) - 4;
	c = ft_readinram(vm, pc, REG_SIZE);
	ft_writeinreg(proc, proc->par[2], c);
	if (c == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	if (vm->args.verb == 1)
		ft_verbldi(a, b, c, pc);
	return (1);
}
