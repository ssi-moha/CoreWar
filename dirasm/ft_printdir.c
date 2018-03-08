/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:59:38 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/08 13:59:40 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void		ft_printdir(t_par *par, int cmd, int out)
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
