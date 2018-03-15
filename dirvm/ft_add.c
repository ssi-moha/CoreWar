/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:22:01 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/15 14:55:45 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

/*
** si a + b -> 0 carry = 1
** sinon carry = 0
*/

int	ft_add(t_process *proc, t_vm *vm)
{
	int		a;
	int		b;
	int		c;

	a = ft_getparvalue(proc, vm, 0);
	b = ft_getparvalue(proc, vm, 1);
	c = a + b;
	ft_writeinreg(proc, proc->par[2], c);	
	if (c == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (1);
}
