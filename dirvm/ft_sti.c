/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:34:44 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/15 17:06:15 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int			ft_sti(t_process *proc, t_vm *vm)
{
	int a;
	int b;
	int value;
	unsigned int	startpos;

	a = ft_getparvalue(proc, vm, 1, MEM_SIZE);
	b = ft_getparvalue(proc, vm, 2, MEM_SIZE);
	value = ft_getparvalue(proc, vm, 0, MEM_SIZE);
	startpos = (proc->pc - 4 + a + b) % MEM_SIZE;
	ft_writeinram(vm, startpos % IDX_MOD, value, REG_SIZE);
	return (1);
}
