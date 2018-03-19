/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:44:33 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/19 14:23:24 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int	ft_or(t_process *proc, t_vm *vm)
{
	int	i;
	int	a;
	int	b;
	int	c;

	a = ft_getparvalue(proc, vm, 0, MEM_SIZE);
	b = ft_getparvalue(proc, vm, 1, MEM_SIZE);
	c = a | b;
	i = REG_SIZE - 1;
	while (i >= 0)
	{
		proc->r[proc->par[2] - 1][i] = c % 256;
		c /= 256;
		i--;
	}
	printf("A %d B %d C %d\n", a, b, c);
	if (c == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (1);
}
