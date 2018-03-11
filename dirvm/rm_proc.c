/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_proc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:18:07 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/11 18:28:13 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		rm_process(int id, t_process **proc)
{
	t_process *tmp;
	t_process *tmp2;
	t_process *tmp3;

	if (!proc)
		return (0);
	tmp = *proc;
	tmp2 = *proc;
	tmp3 = *proc;
	while (tmp->id != id)
	{
		tmp = tmp->next;
		tmp3 = tmp3->next;
		if (tmp2->next->id != id)
			tmp2 = tmp2->next;
	}
	tmp3 = tmp3->next;
	free(tmp);
	tmp2->next = tmp3;
	return (0);
}
