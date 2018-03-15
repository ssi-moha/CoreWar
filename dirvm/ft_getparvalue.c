/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getparvalue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:55:40 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/15 19:35:39 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int	ft_getparvalue(t_process *proc, t_vm *vm, int i, int mod)
{
	int	value;

	if (proc == 0 || vm == 0 || i < 0 || i > 2)
	{
		ft_printf("error\n");
		return (0);
	}
	if (proc->partype[i] == REG_CODE && (proc->par[i] < 1 || proc->par[i] > REG_NUMBER))
	{
		ft_printf("try to access wrong reg number\n");
		return (0);
	}
	value = 0;
	printf("PROC PAR OR %d\n", proc->par[i]);
	printf("TYPE %d\n", proc->partype[i]);
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
	{
		value += vm->ram[(proc->pc + ((proc->par[i] - 3 - 2) % mod)) % MEM_SIZE] << 24;
		value += vm->ram[(proc->pc + ((proc->par[i] - 2 - 2) % mod)) % MEM_SIZE] << 16;
		value += vm->ram[(proc->pc + ((proc->par[i] - 1 - 2) % mod)) % MEM_SIZE] << 8;
		value += vm->ram[(proc->pc + ((proc->par[i] - 2) % mod)) % MEM_SIZE];
		return (value);
	}
	//TAKE REG_SIZE OCTET
	return (0);
}
