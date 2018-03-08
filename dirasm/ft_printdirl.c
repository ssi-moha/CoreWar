/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdirl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:40:41 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/08 13:53:52 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_initp(unsigned int lab, int *d, int *i, unsigned int *nb)
{
	*d = 0;
	*i = DIR_SIZE - 1;
	*nb = lab;
}

void		ft_printdiril(unsigned int lab, int cmd, int out)
{
	unsigned char	p[DIR_SIZE];
	unsigned int	nb;
	int				i[2];

	ft_initp(lab, &i[1], &i[0], &nb);
	if (g_optab[cmd].dirsize == 0)
	{
		while (i[0] >= 0)
		{
			p[i[0]--] = nb % 256;
			nb /= 256;
		}
	}
	else if (g_optab[cmd].dirsize == 1)
	{
		while (i[0] >= DIR_SIZE / 2)
		{
			p[i[0]--] = nb % 256;
			nb /= 256;
		}
		i[1] = DIR_SIZE / 2;
	}
	i[0] = i[1];
	while (i[0] < DIR_SIZE)
		write(out, &p[i[0]++], 1);
}
