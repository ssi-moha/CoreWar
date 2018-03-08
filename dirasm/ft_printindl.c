/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printindl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:22:19 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/08 14:31:42 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

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

void			ft_printindlab(t_par *par, t_instr **begin, t_instr **instr,
		int out)
{
	unsigned int	sizelab;
	int				cmd;

	cmd = ft_findcmd((*begin)->cmd);
	sizelab = count_label(instr, begin, par->par + 1, cmd);
	ft_printindl(sizelab, cmd, out);
}
