/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:40:27 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/15 16:55:14 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int	ft_ldi(t_process *proc, t_vm *vm)
{
	unsigned int a;
	unsigned int b;
	unsigned int c;

	a = ft_getparvalue(proc, vm, 0, MEM_SIZE);
	b = ft_getparvalue(proc, vm, 1, MEM_SIZE);
	c = ft_readinram(vm, proc->pc + ((a + b) % IDX_MOD) - 4, REG_SIZE);	
	printf("LLLLLLDIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII %x\n", a);
	printf("LLLLLLDIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII %x\n", b);
	printf("LLLLLLDIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII %x\n", c);
	ft_writeinreg(proc, proc->par[2], c);
	printf("WRITEINTREG %d\n", ft_getparvalue(proc, vm, 2, MEM_SIZE));
	return (1);
}
