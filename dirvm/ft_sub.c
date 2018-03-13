/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:28:37 by emerabet          #+#    #+#             */
/*   Updated: 2018/03/13 13:33:36 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int			ft_sub(t_process *proc, t_vm *vm)
{
	int		a;
	int		b;
	int		c;

	a = ft_getparvalue(proc, vm, proc->par[0]);
	b = ft_getparvalue(proc, vm, proc->par[1]);
	c = a - b;
	ft_writeinreg(proc, proc->par[2], c);
	proc->carry = 1;
	return (1);
}
