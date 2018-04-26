/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 15:34:44 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/04/26 12:25:47 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_verbsti(int a, int b, int to)
{
	ft_printf("\t\tstore %d + %d = %d to adress %d\n", a, b, a + b, to - 3);
}

int			ft_sti(t_process *proc, t_vm *vm)
{
	int				a;
	int				b;
	int				value;
	unsigned int	startpos;

	if (proc->partype[1] == IND_CODE && proc->par[1] < 0)
		proc->par[1] -= 4;
	a = ft_getparvalue(proc, vm, 1, MEM_SIZE);
	b = ft_getparvalue(proc, vm, 2, MEM_SIZE);
	value = ft_getparvalue(proc, vm, 0, MEM_SIZE);
	startpos = (proc->pc - 4 + ((a + b) % IDX_MOD)) % MEM_SIZE;
	ft_writeinram(vm, startpos, value, proc);
	if (vm->args.verb == 1)
		ft_verbsti(a, b, (proc->pc - 4 + ((a + b) % IDX_MOD)) % MEM_SIZE);
	return (1);
}
