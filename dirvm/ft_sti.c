/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:34:44 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/14 14:00:09 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int			ft_sti(t_process *proc, t_vm *vm)
{
	int a;
	int b;
	int value;
	unsigned int	startpos;

	a = ft_getparvalue(proc, vm, proc->par[1]);
	b = ft_getparvalue(proc, vm, proc->par[2]);
	value = ft_getparvalue(proc, vm, 0);
	startpos = (proc->pc - 3 + a + b) % MEM_SIZE;
	ft_writeinram(vm, startpos, value, REG_SIZE);
	return (1);
}
