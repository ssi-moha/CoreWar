/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadinram.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:29:42 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/10 12:11:50 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_loadplayer(unsigned char *data, int start, t_vm *vm)
{
	int i;
	int prog;

	i = 0;
	prog = 4 + PROG_NAME_LENGTH + 4 +4 + COMMENT_LENGTH + 4;
	while (i < 44)//vm->progsize)
	{
		vm->ram[start] = data[prog++];
		start++;
		i++;
	}
}

void	ft_loadinram(unsigned char *data, int i, int nbplayers, t_vm *vm)
{
	int start;
	
	start = (MEM_SIZE / nbplayers) * (i - 1);
	printf("%d\n", start);
	ft_loadplayer(data, start, vm);
	int j;

	j = 0;
	while (j < MEM_SIZE)
	{
		printf("%3.2x", vm->ram[j]);
		j++;
	}
}
