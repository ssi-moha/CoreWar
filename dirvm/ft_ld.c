/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:00:41 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/04/30 12:34:57 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

/*
** si par[0] == 0 met le carry a 1
** sinon met le carry a 0
*/

int		ft_ld(t_process *proc, t_vm *vm)
{
	int i;

	if (proc->partype[0] == IND_CODE)
		proc->par[0] -= 2;
	i = ft_getparvalue(proc, vm, 0, IDX_MOD);
	if (i == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	if (proc->par[1] > REG_NUMBER)
		return (0);
	ft_writeinreg(proc, proc->par[1], i);
	return (1);
}
