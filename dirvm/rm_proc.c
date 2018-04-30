/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_proc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:18:07 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/04/30 17:45:15 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		rm_process(int id, t_process **proc)
{
	t_process	*tmp;
	t_process 	*next;
	t_process 	*before;

	if (!*proc)
		return (1);
	tmp = *proc;
	next = tmp->next;
	if (id == tmp->id)
	{
		free(tmp);
		tmp = NULL;
		*proc = next;
		return (1);	
	}
	while (tmp)
	{
		if (tmp->id == id)
		{
			next = tmp->next;
			free(tmp);
			tmp = NULL;
			before->next = next;
			return (1);
		}
		before = tmp;
		tmp = tmp->next;
	}
	return (1);
}
