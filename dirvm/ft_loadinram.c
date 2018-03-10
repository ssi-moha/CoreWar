/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadinram.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:29:42 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/10 12:52:49 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_loadplayer(unsigned char *data, int start, t_vm *vm, t_player *p)
{
	int i;
	int prog;

	i = 0;
	prog = 4 + PROG_NAME_LENGTH + 4 +4 + COMMENT_LENGTH + 4;
	while (i < p->header.prog_size)
	{
		vm->ram[start] = data[prog++];
		start++;
		i++;
	}
}

void	ft_loadinram(unsigned char *data, int nbplayers, t_vm *vm, t_player *p)
{
	int start;
	
	start = (MEM_SIZE / nbplayers) * (p->id - 1);
	printf("%d\n", start);
	ft_loadplayer(data, start, vm, p);
	int j;

	j = 0;
}
