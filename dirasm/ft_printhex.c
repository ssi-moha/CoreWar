/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 13:18:41 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/06 15:59:47 by lfujimot         ###   ########.fr       */
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
	int				d;

	d = 0;
	i = DIR_SIZE - 1;
	nb = ft_atoi(par->par + 1);
	if (g_optab[cmd].dirsize == 0)
	{
		while (i >= 0)
		{
			p[i--] = nb % 256;
			nb /= 256;
		}
		d = 0;
	}
	else if (g_optab[cmd].dirsize == 1)
	{
		while (i >= DIR_SIZE / 2)
		{
			p[i--] = nb % 256;
			nb /= 256;
		}
		d = DIR_SIZE / 2;
	}
	i = d;
	while (i < DIR_SIZE)
	{
		write(out, &p[i++], 1);
	}
}

static void ft_printdiril(unsigned int lab, int cmd, int out)
{
	unsigned char	p[DIR_SIZE];
	unsigned int	nb;
	int				i;
	int d;

	d = 0;
	printf("XXXXXXXXXXXXXXXXXXX %u\n", lab);
	i = DIR_SIZE - 1;
	nb = lab;
	if (g_optab[cmd].dirsize == 0)
	{
		while (i >= 0)
		{
			p[i--] = nb % 256;
			nb /= 256;
		}
		d = 0;
	}
	else if (g_optab[cmd].dirsize == 1)
	{
		while (i >= DIR_SIZE / 2)
		{
			p[i--] = nb % 256;
			nb /= 256;
		}
		d = DIR_SIZE / 2;
	}
	i = d;
	printf("DDDDDDDjjjj %d %so dirsize %dooo\n", d, g_optab[cmd].cmd, g_optab[cmd].dirsize);
	while (i < DIR_SIZE)
	{
		write(out, &p[i++], 1);
	}
}

static void ft_printindl(unsigned int lab, int cmd, int out)
{
	unsigned char	p[DIR_SIZE];
	unsigned int	nb;
	int				i;

	printf("XXXXXXXXXXXXXXXXXXX %u\n", lab);
	i = IND_SIZE - 1;
	nb = lab;
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

static void	ft_printdirlab(t_par *par, t_instr **begin, t_instr **instr, int out)
{
	unsigned int sizelab;
	int cmd;

	cmd = ft_findcmd((*instr)->cmd);
	sizelab = count_label(instr, begin, par->par + 2, cmd);
	printf("LABEL SIZE %u\n", sizelab);
	ft_printdiril(sizelab, cmd, out);
}

static void	ft_printindlab(t_par *par, t_instr **begin, t_instr **instr, int out)
{
	unsigned int sizelab;
	int cmd;

	cmd = ft_findcmd((*begin)->cmd);
	sizelab = count_label(instr, begin, par->par + 2, cmd);
	ft_printindl(sizelab, cmd, out);
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
		printf("TMP TYPE %d\n", tmp->type);
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
			ft_printdirlab(tmp, instr, begin, out);
		else if (tmp->type == T_IND + T_LAB)
			ft_printindlab(tmp, instr, begin, out);
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
