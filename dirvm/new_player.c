/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:15:39 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/14 14:37:05 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

t_player	*new_player(unsigned char *data, t_player **prev, unsigned int id, t_vm *vm)
{
	t_player	*tmp;
	t_player	*tmp2;
	t_header	header;
	
	tmp = NULL;
	tmp2 = *prev;
	if (!(tmp = (t_player*)malloc(sizeof(t_player))))
		return (0);
	header.prog_size = ft_checkprogsize(data);
	ft_setname(data, &header);
	ft_setcomment(data, &header);
	tmp->header = header;
	tmp->id = id;
	tmp->number = vm->args.champion[id]; // a rajouter
	tmp->startpos = 0;
	tmp->next = NULL;
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
