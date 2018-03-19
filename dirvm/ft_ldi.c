/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:40:27 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/19 14:37:20 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int	ft_ldi(t_process *proc, t_vm *vm)
{
	unsigned int a;
	unsigned int b;
	unsigned int c;

	a = proc->par[0];
	b = proc->par[1];
	c = ft_readinram(vm, proc->pc + ((a + b) % IDX_MOD) - 4, REG_SIZE);
	ft_writeinreg(proc, proc->par[2], c);
	if (c == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (1);
}
