/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadinram.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:29:42 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/11 11:09:31 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_loadplayer(unsigned char *data, unsigned int start,
							t_vm *vm, t_player *p)
{
	int i;
	int prog;
	char c;

	c = 'p';
	if (p->num == 1)
		c = 'a';
	else if (p->num == 2)
		c = 'b';
	else if (p->num == 3)
		c = 'c';
	else if (p->num == 4)
		c = 'd';

	printf("PLAYER %d\n", p->num);
	i = 0;
	prog = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	while (i < p->header.prog_size)
	{
		vm->ram[start] = data[prog++];
		vm->ramplayer[start] = c;
		start++;
		i++;
	}
}

void		ft_loadinram(unsigned char *data, unsigned int nbplayers,
						t_vm *vm, t_player *p)
{
	unsigned int start;

	fprintf(stderr, "id => %d\n", p->id);
	start = (MEM_SIZE / nbplayers) * (p->id);
	p->startpos = start;
	printf("%d\n", start);
	ft_loadplayer(data, start, vm, p);
	printf("PLAYER %d\n", p->num);
}
