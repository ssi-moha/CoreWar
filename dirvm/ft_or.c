/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:44:33 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/10 16:45:31 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int	ft_or(t_process *proc, t_vm *vm)
{
	int	i;
	int	a;
	int	b;
	int	c;

	a = ft_getparvalue(proc, vm, 0, IDX_MOD);
	b = ft_getparvalue(proc, vm, 1, IDX_MOD);
	a = (a < 0) ? 0 : a;
	b = (b < 0) ? 0 : b;
	c = a | b;
	i = REG_SIZE - 1;
	if (proc->par[2] < 1 || proc->par[2] > 16)
		return (1);
	if (c == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	while (i >= 0)
	{
		proc->r[proc->par[2] - 1][i] = c % 256;
		proc->r[proc->par[2] - 1][i] = c % 256;
		c /= 256;
		i--;
	}
	return (1);
}
