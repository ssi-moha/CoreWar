/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:00:41 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/14 16:01:58 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_corewar.h"

int		ft_ld(t_process *proc, t_vm *vm)
{
	int i;

	i = ft_getparvalue(proc, vm, 0);
	if (proc->par[1] > REG_SIZE)
	{
		proc->carry = 0;
		return (0);
	}
	ft_writeinreg(proc, proc->par[1], i);
	proc->carry = 1;
	return (1);
}
