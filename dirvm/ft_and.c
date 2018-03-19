/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:38:10 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/19 14:25:05 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int	ft_and(t_process *proc, t_vm *vm)
{
	int				i;
	int				a;
	int				b;
	int				c;

	printf("%d %d %d\n", proc->par[0], proc->par[1], proc->par[2]);
	a = ft_getparvalue(proc, vm, 0, MEM_SIZE);
	b = ft_getparvalue(proc, vm, 1, MEM_SIZE);
	c = a & b;
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
