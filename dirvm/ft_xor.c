/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:44:57 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/13 13:43:02 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int	ft_xor(t_process *proc, t_vm *vm)
{
	int				i;
	int				a;
	int				b;
	int				c;				

	if ((proc->partype[0] == REG_CODE && (proc->par[0] < 1 || proc->par[0] > 16)) || (proc->partype[1] == REG_CODE && (proc->par[1] < 1 || proc->par[1] > 16)) || proc->par[2] < 1 || proc->par[2] > 16)
		return (0);
	a = ft_getparvalue(proc, vm, 0);
	b = ft_getparvalue(proc, vm, 1);
	c = a ^ b;
	i = REG_SIZE - 1;
	while (i >= 0)
	{
		proc->r[proc->par[2] - 1][i] = c % 256;
		c /= 256;
		i--;
	}
	printf("A %d B %d C %d\n", a, b, c);
	return (1);
}
