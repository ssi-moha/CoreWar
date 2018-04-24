/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converttohex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 13:18:41 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/24 11:59:44 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void		ft_convcmd(t_instr **instr)
{
	(*instr)->sizeoctet += 1;
}

static void		ft_convparsize(t_instr **instr)
{
	int cmd;

	cmd = ft_findcmd((*instr)->cmd);
	(*instr)->sizeoctet += g_optab[cmd].octpar;
}

static void		ft_convparams(t_instr **instr)
{
	t_par	*tmp;
	int		cmd;

	tmp = (*instr)->params;
	while (tmp)
	{
		cmd = ft_findcmd((*instr)->cmd);
		if (tmp->type == T_REG)
			(*instr)->sizeoctet += 1;
		else if (tmp->type == T_DIR || tmp->type == T_DIR + T_LAB)
		{
			if (g_optab[cmd].dirsize == 0)
				(*instr)->sizeoctet += 4;
			else if (g_optab[cmd].dirsize == 1)
				(*instr)->sizeoctet += 2;
		}
		else if (tmp->type == T_IND || tmp->type == T_IND + T_LAB)
			(*instr)->sizeoctet += 2;
		tmp = tmp->next;
	}
}

void			ft_converttohex(t_instr *instr)
{
	t_instr *tmp;

	tmp = instr;
	while (tmp)
	{
		if (ft_strcmp(tmp->cmd, "tmp") != 0)
		{
			ft_convcmd(&tmp);
			ft_convparsize(&tmp);
			ft_convparams(&tmp);
		}
		tmp = tmp->next;
	}
}
