/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:38:10 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/12 14:36:31 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar"

static int	ft_getparvalue(t_process *proc, t_vm *vm, int i)
{
	if (proc->partype[i] == REG_CODE)
		return (proc->r[proc->par[i]]);
	else if (proc->partype[i] == DIR_CODE)
		return (proc->par[i]);
	else if (proc->partype[i] == IND_CODE)
		return (vm->ram[proc->pc + proc->par[i]]);
	return (0);
}

void	ft_and(t_process *proc, t_vm *vm)
{
	int				i;
	int				a;
	int				b;
	int				c;				

	a = ft_getparvalue(proc, vm, 0);
	b = ft_getparvalue(proc, vm, 1);
	c = a & b;
	i = REG_SIZE - 1;
	while (i >= 0)
	{
		proc->r[proc->par[2]][i] = c % 256;
		c /= 256;
		i--;
	}
	printf("A %d B %d C %d\n", a, b, c);
}
