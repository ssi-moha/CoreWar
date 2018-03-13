/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getparvalue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 16:55:40 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/13 13:49:39 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int	ft_getparvalue(t_process *proc, t_vm *vm, int i)
{
	int	value;

	if (proc == 0 || vm == 0 || i < 0 || i > 2)
		return (0);
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
		return (vm->ram[(proc->pc + proc->par[i]) % MEM_SIZE]);
	//TAKE REG_SIZE OCTET
	return (0);
}
