/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadnewinstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 16:23:56 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/10 17:11:35 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_loadpartype(t_process *p, t_vm *vm)
{
	int				i;
	unsigned char	ptype;

	ft_memset(p->partype, 0 , 3);
	i = 0;
	printf("CMD %d\n", p->cmd);
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

static int	ft_getparvalueinram(t_process *p, t_vm *vm, int np)
{
	int	value;
	short v;

	v = 0;
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
		v += vm->ram[p->pc++ % MEM_SIZE] << 8;
		v += vm->ram[p->pc++ % MEM_SIZE];
		value = v;
	}
	return (value);
}

static void	ft_loadpar(t_process *p, t_vm *vm)
{
	int i;

	ft_setint(p->par, 0, 3);
	i = 0;
	while (i < g_optab[p->cmd - 1].nbpar)
	{
		p->par[i] = ft_getparvalueinram(p, vm, i);
		i++;
	}
}

void	ft_loadnewinstr(t_process *p, t_vm *vm)
{
//	printf("P %d CYCLE %d\n", p->pc, p->cycle);
	if (p->cycle == 0)
	{
		if (p->cmd != DEFAULT)
		{
//			printf("DO ACTION %s\n", g_optab[p->cmd - 1].cmd);
			func_tab(p->cmd, p, vm);
		//	sleep(1);
			ft_showram(vm->ram);
		}

		p->cmd = vm->ram[p->pc++ % MEM_SIZE];
		if (p->cmd > 0 && p->cmd <= 16)
		{
//			printf("CMD %d\n", p->cmd);
			ft_loadpartype(p, vm);

//			printf("PAR %d %d %d\n", p->partype[0], p->partype[1], p->partype[2]); 
			ft_loadpar(p, vm);
//			printf("VALUE %d %d %d\n", p->par[0], p->par[1], p->par[2]);
			p->cycle = g_optab[p->cmd - 1].nbcycle;
		}
	}
}
