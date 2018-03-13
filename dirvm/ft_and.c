/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:38:10 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/13 13:43:15 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int	ft_and(t_process *proc, t_vm *vm)
{
	int				i;
	int				a;
	int				b;
	int				c;				

	printf("%d %d %d\n", proc->par[0], proc->par[1], proc->par[2]);
	if ((proc->partype[0] == REG_CODE && (proc->par[0] < 1 || proc->par[0] > 16)) || (proc->partype[1] == REG_CODE && (proc->par[1] < 1 || proc->par[1] > 16)) || proc->par[2] < 1 || proc->par[2] > 16)
		return (0);
	a = ft_getparvalue(proc, vm, 0);
	b = ft_getparvalue(proc, vm, 1);
	c = a & b;
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
