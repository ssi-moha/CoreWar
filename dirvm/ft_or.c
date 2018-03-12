/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:44:33 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/12 16:12:04 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static int	ft_getparvalue(t_process *proc, t_vm *vm, int i)
{
	int	value;

	value = 0;
	if (proc->partype[i] == REG_CODE)
	{
		value += proc->r[proc->par[i] - 1][0] << 24;
		value += proc->r[proc->par[i] - 1][1] << 16;
		value += proc->r[proc->par[i] - 1][2] << 8;
		value += proc->r[proc->par[i] - 1][3];
		return (value);
	}
	else if (proc->partype[i] == DIR_CODE)
		return (proc->par[i]);
	else if (proc->partype[i] == IND_CODE)
		return (vm->ram[proc->pc + proc->par[i]]);
	return (0);
}

void	ft_or(t_process *proc, t_vm *vm)
{
	int				i;
	int				a;
	int				b;
	int				c;				

	a = ft_getparvalue(proc, vm, 0);
	b = ft_getparvalue(proc, vm, 1);
	c = a | b;
	i = REG_SIZE - 1;
	while (i >= 0)
	{
		proc->r[proc->par[2 - 1]][i] = c % 256;
		c /= 256;
		i--;
	}
	printf("A %d B %d C %d\n", a, b, c);
}
