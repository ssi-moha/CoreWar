/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readinram.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:43:59 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/14 17:04:12 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

unsigned int	ft_readinram(t_vm *vm, unsigned int pos, unsigned int nboctet)
{
	unsigned int	i;
	unsigned int	value;
	int				b;

	b = nboctet - 1;
	value = 0;
	i = pos - (nboctet - 1);
	while (i <= pos)
	{
		value += vm->ram[i % MEM_SIZE] << (8 * b);
		b--;
		i++;
	}
	return (value);
}
