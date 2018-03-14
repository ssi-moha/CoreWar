/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writeinreg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:05:44 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/14 17:14:18 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void	ft_writeinreg(t_process *p, int regnb, unsigned int nb)
{
	int i;

	i = REG_SIZE - 1;
	while (i >= 0)
	{
		p->r[regnb - 1][i] = nb % 256;
		nb /= 256;
		i--;
	}
}
