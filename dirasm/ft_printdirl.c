/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdirl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:40:41 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/08 13:43:30 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void		ft_printdiril(unsigned int lab, int cmd, int out)
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
