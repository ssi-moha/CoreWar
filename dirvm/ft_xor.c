/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:44:57 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/30 15:39:27 by lfujimot         ###   ########.fr       */
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
	ft_printf("A %d B %d\n", a, b);
	c = a ^ b;
	i = REG_SIZE - 1;
	if (proc->par[2] <= 1 || proc->par[2] >= REG_NUMBER)
	{
		proc->carry = 0;
		return (-1);
	}
	while (i >= 0)
	{
		proc->r[proc->par[2] - 1][i] = c % 256;
		c /= 256;
		i--;
	}
	if (c == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	ft_printf("XOR CARRY %d\n", proc->carry);
	return (1);
}
