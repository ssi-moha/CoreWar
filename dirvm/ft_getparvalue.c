/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getparvalue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:55:40 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/01 19:17:38 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static int	ft_getreg(t_process *proc, int i)
{
	int	value;

	value = 0;
	value += proc->r[proc->par[i] - 1][0] << 24;
	value += proc->r[proc->par[i] - 1][1] << 16;
	value += proc->r[proc->par[i] - 1][2] << 8;
	value += proc->r[proc->par[i] - 1][3];
	return (value);
}

static int	ft_getind(t_vm *vm, t_process *proc, int mod, int i)
{
	int	value;
	int	p;
	p = (proc->pc + ((proc->par[i]) % mod)) % MEM_SIZE;
//	if (p < 0)
//		p = MEM_SIZE + p;
	value = 0;
	value += vm->ram[p] << 24;
	value += vm->ram[p] << 16;
	value += vm->ram[p] << 8;
	value += vm->ram[p];
	return (value);
}

int			ft_getparvalue(t_process *proc, t_vm *vm, int i, int mod)
{
	if (proc == 0 || vm == 0 || i < 0 || i > 2)
	{
		return (0);
	}
	if (proc->partype[i] == REG_CODE && (proc->par[i] < 1 ||
		proc->par[i] > REG_NUMBER))
	{
		return (0);
	}
	if (proc->partype[i] == REG_CODE)
		return (ft_getreg(proc, i));
	else if (proc->partype[i] == DIR_CODE)
		return (proc->par[i]);
	else if (proc->partype[i] == IND_CODE)
		return (ft_getind(vm, proc, mod, i));
	return (0);
}
