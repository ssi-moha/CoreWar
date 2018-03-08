/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:59:38 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/08 14:15:18 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static unsigned char	ft_mod(unsigned int *tp)
{
	unsigned char p;

	p = *tp % 256;
	*tp /= 256;
	return (p);
}

static void				ft_initp(int *d, int *i, int *nb, unsigned int *tp)
{
	*d = 0;
	*i = DIR_SIZE - 1;
	if (*nb >= 0)
		*tp = *nb;
}

static void				ft_dirshort(int nb, unsigned int *tp)
{
	if (nb < 0)
		*tp = 65536 + nb;
}

void					ft_printdir(t_par *par, int cmd, int out)
{
	unsigned char	p[DIR_SIZE];
	int				nb;
	int				i;
	int				d;
	unsigned int	tp;

	nb = ft_atoi(par->par + 1);
	ft_initp(&d, &i, &nb, &tp);
	if (g_optab[cmd].dirsize == 0)
	{
		if (nb < 0)
			tp = 4294967296 + nb;
		while (i >= 0)
			p[i--] = ft_mod(&tp);
	}
	else if (g_optab[cmd].dirsize == 1)
	{
		ft_dirshort(nb, &tp);
		while (i >= DIR_SIZE / 2)
			p[i--] = ft_mod(&tp);
		d = DIR_SIZE / 2;
	}
	i = d;
	while (i < DIR_SIZE)
		write(out, &p[i++], 1);
}
