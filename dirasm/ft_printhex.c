/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 13:18:41 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/05 18:52:28 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_printcmd(char *cmd, int out)
{
	unsigned char c;

	c = g_optab[ft_findcmd(cmd)].numcmd;
	write(out, &c, 1);
	printf("INSTRUCTION NUM %d\n", c);
}

static int	ft_rettype(int type)
{
	if (type == T_REG)
		return (REG_CODE);
	else if (type == T_DIR || type == T_DIR + T_LAB)
		return (DIR_CODE);
	else if (type == T_IND || type == T_IND + T_LAB)
		return (IND_CODE);
	return (-1);
}

static void	ft_printsizepar(t_instr *instr, int out)
{
	int cmd;
	t_par *tmp;
	unsigned char	p;
	int i;

	i = 1;
	p = 0;
	cmd = ft_findcmd(instr->cmd);
	if (g_optab[cmd].octpar == 0)
		return ;
	else
	{
		tmp = instr->params;
		while (tmp)
		{
			if (i == 1)
				p = p  | (ft_rettype(tmp->type) << 6);
			else if (i == 2)
				p = p | (ft_rettype(tmp->type) << 4);
			else if (i == 3)
				p = p | (ft_rettype(tmp->type) << 2);
			tmp = tmp->next;
			i++;
		}
	}
	write(out, &p, 1);
	printf("HEXAAAAAAAAAAAAAAAAAAA %x %d\n", p, p);		
}

void	ft_printhex(t_instr *instr, int out)
{
	t_instr *tmp;

	tmp = instr;
	while (tmp)
	{
		ft_printcmd(tmp->cmd, out);
		ft_printsizepar(tmp, out);
		tmp = tmp->next;
	}	
}
