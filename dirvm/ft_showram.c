/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_showram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 12:44:29 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/11 14:34:45 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void	ft_showram(unsigned char *ram)
{
	int				i;
	int				n;

	i = 0;
	n = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%3.2x", ram[i]);
		if (n == 63)
		{
			ft_printf("\n");
			n = -1;
		}
		n++;
		i++;
	}
}
