/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 13:18:41 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/06 12:45:21 by lfujimot         ###   ########.fr       */
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

static void ft_printdir(t_par *par, int cmd, int out)
{
	unsigned char	p[DIR_SIZE];
	int				nb;
	int				i;

	i = DIR_SIZE - 1;
	nb = ft_atoi(par->par + 1);
	if (g_optab[cmd].dirsize == 0)
	{
		while (i >= 0)
		{
			p[i--] = nb % 256;
			nb /= 256;
		}
	}
	else if (g_optab[cmd].dirsize == 1)
	{
		while (i >= DIR_SIZE / 2)
		{
			p[i--] = nb % 256;
			nb /= 256;
		}
	}
	i = 0;
	while (i < DIR_SIZE)
	{
		write(out, &p[i++], 1);
	}
}

static void ft_printind(t_par *par, int cmd, int out)
{
	unsigned char	p[IND_SIZE];
	int				nb;
	int				i;

	i = IND_SIZE - 1;
	nb = ft_atoi(par->par + 1);
	while (i >= 0)
	{
		p[i--] = nb % 256;
		nb /= 256;
	}
	i = 0;
	while (i < IND_SIZE)
	{
		write(out, &p[i++], 1);
	}
}

static void	ft_printdirlab(t_par *par, t_instr **instr, t_instr **begin)
{
	unsigned int sizelab;

	sizelab = count_label(instr, begin, par->par + 2);
	printf("SIZE LABEL %d", sizelab);
}

static void	ft_printparams(t_par **par, char *cmd, int out, t_instr **instr, t_instr **begin)
{
	t_par *tmp;
	int c;
	unsigned char p[4];

	c = ft_findcmd(cmd);
	tmp = *par;
	while (tmp)
	{
		if (tmp->type == T_REG)
		{
			p[0] = (unsigned char)ft_atoi(tmp->par + 1);
			write(out, &p[0], 1);
		}
		else if (tmp->type == T_DIR)
			ft_printdir(tmp, c, out);
		else if (tmp->type == T_IND)
			ft_printind(tmp, c, out);
		else if (tmp->type == T_DIR + T_LAB)
			ft_printdirlab(tmp, instr, begin);
		//else if (tmp->type == T_IND + T_LAB)
		//	...
		tmp = tmp->next;
	}
}

void	ft_printhex(t_instr *instr, int out)
{
	t_instr *tmp;

	tmp = instr;
	while (tmp)
	{
		ft_printcmd(tmp->cmd, out);
		ft_printsizepar(tmp, out);
		ft_printparams(&tmp->params, tmp->cmd, out, &instr, &tmp);
		tmp = tmp->next;
	}	
}
