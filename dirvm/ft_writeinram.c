/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writeinram.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 13:23:42 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/25 17:08:50 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void	ft_writeinram(t_vm *vm, unsigned int pos,
		unsigned int value, t_process *p)
{
	int		i;
	char	c;

	c = 'p';
	if (p->num == 1)
		c = 'A';
	else if (p->num == 2)
		c = 'B';
	else if (p->num == 3)
		c = 'C';
	else if (p->num == 4)
		c = 'D';
	i = REG_SIZE - 1;
	while (i >= 0)
	{
		vm->ramplayer[(pos) % MEM_SIZE] = c;
		vm->ram[(pos--) % MEM_SIZE] = value % 256;
		value /= 256;
		i--;
	}
}
