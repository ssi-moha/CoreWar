/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:34:44 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/13 15:43:38 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int			ft_sti(t_process *proc, t_vm *vm)
{
	int a;
	int b;
	int value;

	a = ft_getparvalue(proc, vm, proc->par[1]);
	b = ft_getparvalue(proc, vm, proc->par[2]);
	value = ft_getparvalue(proc, vm, proc->par[0]);
	vm->ram[a + b] = (unsigned char)value;
	return (1);
}
