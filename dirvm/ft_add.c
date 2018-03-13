/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:22:01 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/13 13:20:58 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void	ft_add(t_process *proc, t_vm *vm)
{
	int		a;
	int		b;
	int		c;

	a = ft_getparvalue(proc, vm, proc->par[0]);
	b = ft_getparvalue(proc, vm, proc->par[1]);
	c = a + b;
	ft_writeinreg(proc, proc->par[2], c);	
	proc->carry = 1;
}
