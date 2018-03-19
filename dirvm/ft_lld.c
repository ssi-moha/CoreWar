/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 16:40:47 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/19 12:44:37 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

/*
** si par[0] == 0 met le carry a 1
** sinon met le carry a 0
*/

int		ft_lld(t_process *proc, t_vm *vm)
{
	int i;

	if (proc->partype[0] == IND_CODE)
		proc->par[0] -= 4;
	i = ft_getparvalue(proc, vm, 0, MEM_SIZE);
	i = i << 16;
	i = i >> 16;
	if (i == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	if (proc->par[1] > REG_SIZE)
		return (0);
	ft_writeinreg(proc, proc->par[1], i);
	return (1);
}
