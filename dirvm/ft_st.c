/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:52:01 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/04/10 14:06:30 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		ft_st(t_process *proc, t_vm *vm)
{
	int i;

	i = ft_getparvalue(proc, vm, 0, MEM_SIZE);
	if (proc->partype[1] == REG_CODE)
		ft_writeinreg(proc, proc->par[1], i);
	else if (proc->partype[1] == IND_CODE)
		ft_writeinram(vm, (proc->pc - 2 + (proc->par[1] % IDX_MOD))
						% MEM_SIZE, i, 4, proc);
	return (1);
}
