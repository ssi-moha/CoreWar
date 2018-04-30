/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkinlive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:22:00 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/30 17:45:17 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void	ft_checkinlive(t_process **ps, t_vm *vm)
{
	t_process *tmp;
	t_process *next;

	tmp = *ps;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->inlive == 0)
		{
			rm_process(tmp->id, ps);
			--(vm->totalprocess);
		}
		else
			tmp->inlive = 0;
		tmp = next;
	}
}
