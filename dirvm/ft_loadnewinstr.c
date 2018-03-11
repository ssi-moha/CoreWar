/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadnewinstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 16:23:56 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/11 17:09:44 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_loadpartype(t_process *p, t_vm *vm)
{
	int	i;
	unsigned char ptype;

	i = 0;
	if (g_optab[p->cmd - 1].octpar == 0)
	{
		while (i < g_optab[p->cmd - 1].nbpar)
			p->partype[i++] = vm->ram[p->pc++ % MEM_SIZE];
	
	}
	else
	{
		ptype = vm->ram[p->pc++ % MEM_SIZE];
		ptype /= 4;
		i = 3;
		while (i >= 0)
		{
			p->partype[i--] = ptype % 4;
			ptype /= 4;
		}
	}
}

void	ft_loadnewinstr(t_process *p, t_vm *vm)
{
	if (p->cycle == 0)
	{
		if (p->cmd != DEFAULT)
			printf("DO ACTION\n");
		p->cmd = vm->ram[p->pc++ % MEM_SIZE];
		printf("CMD %d\n", p->cmd);
		ft_loadpartype(p, vm);

//		printf("PAR %d %d %d\n", 
	}
}
