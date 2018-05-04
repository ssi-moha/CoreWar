/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_winner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:33:40 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/03 08:45:17 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void	ft_winner(t_vm *vm, int out)
{
	t_player	*tmp;

	tmp = vm->players;
	while (tmp)
	{
		if (tmp->number == vm->lastlive)
			break ;
		tmp = tmp->next;
	}
	if (tmp != 0)
		ft_printffd(1, "le joueur %d(%s) a gagne\n", tmp->number,
		tmp->header.prog_name);
	else
		ft_printffd(1, "le joueur %d(%s) a gagne\n", vm->players->number,
		vm->players->header.prog_name);
	ft_visu(vm, out, vm->players->header.prog_name);
	close(out);
	exit(EXIT_SUCCESS);
}
