/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_proc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:18:07 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/16 16:14:05 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		rm_process(int id, t_process **proc)
{
	t_process *tmp;
	t_process *tmp2;
	t_process *tmp3;
	int			last;

	last = 0;
	if (!proc)
		return (0);
	tmp = *proc;
	if (tmp->next == 0)
	{
		free(tmp);
		tmp = 0;
		last = 1;
		*proc = 0;
		return (0);
	}
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
	fprintf(stderr, "Je veux free : %d\n", tmp->id);
	free(tmp);
	fprintf(stderr, "Je veux free : DONE\n");
		tmp = NULL;
	tmp2->next = tmp3;
	if (last == 1)
		*proc = 0;
	return (0);
}
