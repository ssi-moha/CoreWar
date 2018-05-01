/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:28:37 by emerabet          #+#    #+#             */
/*   Updated: 2018/05/01 19:48:41 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

/*
** si a -> carry = 1
** sinon carry = 0
*/

int			ft_sub(t_process *proc, t_vm *vm)
{
	int		a;
	int		b;
	int		c;

	a = ft_getparvalue(proc, vm, 0, MEM_SIZE);
	b = ft_getparvalue(proc, vm, 1, MEM_SIZE);
	c = a - b;
	ft_printf("a%d b%d c%d\n", a,b,c);
	ft_writeinreg(proc, proc->par[2], c);
	if (c == 0)
		proc->carry = 1;
	else
		proc->carry = 0;
	return (1);
}
