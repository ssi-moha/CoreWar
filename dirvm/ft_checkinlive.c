/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkinlive.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:22:00 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/19 14:35:43 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void	ft_checkinlive(t_process **ps)
{
	t_process *tmp;

	tmp = *ps;
	while (tmp)
	{
		if (tmp->inlive == 0)
			rm_process(tmp->id, ps);
		else
			tmp->inlive = 0;
		tmp = tmp->next;
	}
}
