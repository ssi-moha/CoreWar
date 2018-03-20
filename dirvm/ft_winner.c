/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_winner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:33:40 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/20 15:50:54 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void	ft_winner(t_vm *vm)
{
	t_player	*tmp;

	tmp = vm->players;
	while (tmp)
	{
		if (tmp->id == vm->lastlive)
			break ;
		tmp = tmp->next;
	}
	if (tmp != 0)
		ft_printf("le joueur %d(%s) a gagne\n",tmp->id, tmp->header.prog_name);
	else
		ft_printf("le joueur %d(%s) a gagne\n",vm->players->id, vm->players->header.prog_name);
}
