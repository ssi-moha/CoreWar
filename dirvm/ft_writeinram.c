/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writeinram.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:23:42 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/14 14:32:55 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void	ft_writeinram(t_vm *vm, unsigned int pos, unsigned int value, int nboct)
{
	int i;

	i = nboct - 1;
	while (i >= 0)
	{
		vm->ram[pos--] = value % 256;
		value /= 256;
		i--;
	}
}
