/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 11:56:03 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/04/26 15:29:03 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void		ft_printind(t_par *par, int out)
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

static void		ft_printreg(t_par *tmp, unsigned char p[4], int out)
{
	int				n;

	n = ft_atoi(tmp->par + 1);
	if (n <= 0 || n > REG_NUMBER)
		exit(error_mess("ERROR REGISTER DOES NOT EXIST\n"));
	p[0] = (unsigned char)n;
	write(out, &p[0], 1);
}

static void		ft_printparams(int out, t_instr **instr, t_instr **begin)
{
	t_par			*tmp;
	int				c;
	unsigned char	p[4];

	c = ft_findcmd((*begin)->cmd);
	tmp = (*begin)->params;
	while (tmp)
	{
		if (tmp->type == T_REG)
			ft_printreg(tmp, p, out);
		else if (tmp->type == T_DIR)
			ft_printdir(tmp, c, out);
		else if (tmp->type == T_IND)
			ft_printind(tmp, out);
		else if (tmp->type == T_DIR + T_LAB)
			ft_printdirlab(tmp, instr, begin, out);
		else if (tmp->type == T_IND + T_LAB)
			ft_printindlab(tmp, instr, begin, out);
		tmp = tmp->next;
	}
}

void			ft_printhex(t_instr *instr, int out)
{
	t_instr			*tmp;
	unsigned char	c;

	tmp = instr;
	while (tmp)
	{
		if (ft_strcmp(tmp->cmd, "tmp") != 0)
		{
			c = g_optab[ft_findcmd(tmp->cmd)].numcmd;
			write(out, &c, 1);
			ft_printsizepar(tmp, out);
			ft_printparams(out, &instr, &tmp);
		}
		tmp = tmp->next;
	}
}
