/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadnewinstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 16:23:56 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/11 18:33:02 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_loadpartype(t_process *p, t_vm *vm)
{
	int	i;
	unsigned char ptype;

	ft_memset(p->partype, 0 , 3);
	i = 0;
	if (g_optab[p->cmd - 1].octpar == 0)
	{
		if (g_optab[p->cmd - 1].typepar[0] == T_DIR)
			p->partype[0] = DIR_CODE;
		else if (g_optab[p->cmd - 1].typepar[0] == T_IND)
			p->partype[0] = IND_CODE;
		else if (g_optab[p->cmd - 1].typepar[0] == T_REG)
			p->partype[0] = REG_CODE;
	}
	if (g_optab[p->cmd - 1].octpar == 1)
	{
		ptype = vm->ram[p->pc++ % MEM_SIZE];
		ptype /= 4;
		i = 2;
		while (i >= 0)
		{
			p->partype[i--] = ptype % 4;
			ptype /= 4;
		}
	}
}

static int	ft_getparvalue(t_process *p, t_vm *vm, int np)
{
	int	value;

	value = 0;
	if (p->partype[np] == REG_CODE)
		value += vm->ram[p->pc++ % MEM_SIZE];
	else if (p->partype[np] == DIR_CODE && g_optab[p->cmd - 1].dirsize == 0)
	{
		value += vm->ram[p->pc++ % MEM_SIZE] << 24;
		value += vm->ram[p->pc++ % MEM_SIZE] << 16;
		value += vm->ram[p->pc++ % MEM_SIZE] << 8;
		value += vm->ram[p->pc++ % MEM_SIZE];
	}
	else if (p->partype[np] == IND_CODE || (p->partype[np] == DIR_CODE && g_optab[p->cmd - 1].dirsize == 1))
	{
		value += vm->ram[p->pc++ % MEM_SIZE] << 8;
		value += vm->ram[p->pc++ % MEM_SIZE];
	}
	return (value);
}

static void	ft_loadpar(t_process *p, t_vm *vm)
{
	int i;
	
//	p->par[0] = 0;
//	p->par[1] = 0;
//	p->par[2] = 0;
	ft_setint(p->par, 0, 3);
	i = 0;
	printf("NB PAR %d\n", g_optab[p->cmd - 1].nbpar);
	while (i < g_optab[p->cmd - 1].nbpar)
	{
		p->par[i] = ft_getparvalue(p, vm, i);
		printf("V %d\n", p->par[i]);
		i++;
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

		printf("PAR %d %d %d\n", p->partype[0], p->partype[1], p->partype[2]); 
		ft_loadpar(p, vm);
		printf("VALUE %d %d %d\n", p->par[0], p->par[1], p->par[2]);
	}
}
