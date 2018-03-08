/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:56:03 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/08 13:30:55 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void		ft_printcmd(char *cmd, int out)
{
	unsigned char c;

	c = g_optab[ft_findcmd(cmd)].numcmd;
	write(out, &c, 1);
}

static void		ft_printdir(t_par *par, int cmd, int out)
{
	unsigned char	p[DIR_SIZE];
	int				nb;
	int				i;
	int				d;
	unsigned int	tp;

	d = 0;
	i = DIR_SIZE - 1;
	nb = ft_atoi(par->par + 1);
	if (nb >= 0)
		tp = nb;
	if (g_optab[cmd].dirsize == 0)
	{
		if (nb < 0)
			tp = 4294967296 + nb;
		while (i >= 0)
		{
			p[i--] = tp % 256;
			tp /= 256;
		}
		d = 0;
	}
	else if (g_optab[cmd].dirsize == 1)
	{
		if (nb < 0)
			tp = 65536 + nb;
		while (i >= DIR_SIZE / 2)
		{
			p[i--] = tp % 256;
			tp /= 256;
		}
		d = DIR_SIZE / 2;
	}
	i = d;
	while (i < DIR_SIZE)
	{
		write(out, &p[i++], 1);
	}
}

static void		ft_printdiril(unsigned int lab, int cmd, int out)
{
	unsigned char	p[DIR_SIZE];
	unsigned int	nb;
	int				i;
	int				d;

	d = 0;
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
	while (i < DIR_SIZE)
		write(out, &p[i++], 1);
}

static void		ft_printindl(unsigned int lab, int cmd, int out)
{
	unsigned char	p[DIR_SIZE];
	unsigned int	nb;
	int				i;

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

static void		ft_printind(t_par *par, int cmd, int out)
{
	unsigned char	p[IND_SIZE];
	int				nb;
	int				i;

	i = IND_SIZE - 1;
	nb = ft_atoi(par->par);
	if (nb < 0)
		nb = 65536 + nb;
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

static void		ft_printdirlab(t_par *par, t_instr **begin, t_instr **instr,
		int out)
{
	unsigned int	sizelab;
	int				cmd;

	cmd = ft_findcmd((*instr)->cmd);
	sizelab = count_label(instr, begin, par->par + 2, cmd);
	ft_printdiril(sizelab, cmd, out);
}

static void		ft_printindlab(t_par *par, t_instr **begin, t_instr **instr,
		int out)
{
	unsigned int	sizelab;
	int				cmd;

	cmd = ft_findcmd((*begin)->cmd);
	sizelab = count_label(instr, begin, par->par + 1, cmd);
	ft_printindl(sizelab, cmd, out);
}

static void		ft_printparams(int out, t_instr **instr, t_instr **begin)
{
	t_par			*tmp;
	int				c;
	unsigned char	p[4];
	int				n;

	c = ft_findcmd((*begin)->cmd);
	tmp = (*begin)->params;
	while (tmp)
	{
		if (tmp->type == T_REG)
		{
			n = ft_atoi(tmp->par + 1);
			if (n <= 0 || n > REG_NUMBER)
				exit(error_mess("ERROR REGISTER DOES NOT EXIST\n"));
			p[0] = (unsigned char)n;
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
		ft_printparams(out, &instr, &tmp);
		tmp = tmp->next;
	}
}
