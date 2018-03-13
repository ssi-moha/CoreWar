/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:27:41 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/13 14:35:50 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		ft_lld(t_process *proc, t_vm *vm)
{
	int i;

	i = ft_getparvalue(proc, vm, proc->par[0]);
	if (proc->par[1] > REG_SIZE || proc->par[1] < 1)
		return (0);
	ft_writeinreg(proc, proc->par[1], i);
	proc->pc = proc->pc + 34;
	return (1);
}
