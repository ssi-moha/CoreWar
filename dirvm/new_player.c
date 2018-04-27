/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:15:39 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/27 16:05:20 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void		ft_initpl(t_player *p)
{
	p->nblive = 0;
	p->startpos = 0;
	p->next = NULL;
}

t_player	*new_player(unsigned char *data, t_player **prev,
						unsigned int id, t_vm *vm)
{
	t_player	*tmp;
	t_player	*tmp2;
	t_header	header;

	tmp = NULL;
	tmp2 = *prev;
	if (!(tmp = (t_player*)malloc(sizeof(t_player))))
		exit(EXIT_FAILURE);
	header.prog_size = ft_checkprogsize(data);
	ft_setname(data, &header);
	ft_setcomment(data, &header);
	tmp->header = header;
	tmp->id = id;
	tmp->num = vm->incplayer++;
	tmp->number = vm->args.champion[tmp->num - 1];
	ft_initpl(tmp);
	if (!*prev)
		*prev = tmp;
	else
	{
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
	}
	return (tmp);
}
