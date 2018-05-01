/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadnewinstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 16:23:56 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/01 18:59:10 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_loadpartype(t_process *p, t_vm *vm)
{
	int				i;
	unsigned char	ptype;

	ft_memset(p->partype, 0, 3);
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

static int	ft_getparvalueinram(t_process *p, t_vm *vm, int np)
{
	int		value;
	short	v;

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
	else if (p->partype[np] == IND_CODE || (p->partype[np] == DIR_CODE &&
			g_optab[p->cmd - 1].dirsize == 1))
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

static void	ft_verb(t_process *p, t_vm *vm)
{
	int i;

	ft_printf("cycle %d (pc at %d) P %d do -> %s (carry = %d)", vm->cycletotal, p->pc, p->id,
			g_optab[p->cmd - 1].cmd, p->carry);
	i = 0;
	while (i < g_optab[p->cmd - 1].nbpar)
	{
		if (p->partype[i] == 1)
			ft_printf(" REG: %d", p->par[i]);
		else if (p->partype[i] == 2)
			ft_printf(" DIR: %d", p->par[i]);
		else if (p->partype[i] == 3)
			ft_printf(" IND: %d", p->par[i]);
		i++;
	}
	ft_printf("\n");
}

void		ft_loadnewinstr(t_process *p, t_vm *vm)
{
	if (p->cycle <= 0)
	{
		if (p->cmd > 0 && p->cmd <= 16)
		{
			if (vm->args.verb == 1)
				ft_verb(p, vm);
			func_tab(p->cmd, p, vm);
		}
		p->lastpc = p->pc;
		p->cmd = vm->ram[p->pc++ % MEM_SIZE];
		if (p->cmd > 0 && p->cmd <= 16)
		{
			ft_loadpartype(p, vm);
			ft_loadpar(p, vm);
			if (p->cycle == -1)
				p->cycle = g_optab[p->cmd - 1].nbcycle - 1;
			else
				p->cycle = g_optab[p->cmd - 1].nbcycle;
		}
		else
			p->cycle = 1;
	}
}
