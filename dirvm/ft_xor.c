/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:44:57 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/03 08:30:04 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int	ft_xor(t_process *proc, t_vm *vm)
{
	int	i;
	int	a;
	int	b;
	int	c;

	a = ft_getparvalue(proc, vm, 0, MEM_SIZE);
	b = ft_getparvalue(proc, vm, 1, MEM_SIZE);
	c = a ^ b;
	i = REG_SIZE - 1;
	proc->pc--;
	if (proc->par[2] < 1 || proc->par[2] > 16)
		return (1);
	if (c == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	while (i >= 0)
	{
		proc->r[proc->par[2] - 1][i] = c % 256;
		c /= 256;
		i--;
	}
	return (1);
}
