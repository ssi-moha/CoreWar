/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_proc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:18:07 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/05/02 19:17:27 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static t_process	**ft_ff(t_process **f, t_process **toret)
{
	free(*f);
	*f = NULL;
	return (toret);
}

int					rm_process(int id, t_process **proc)
{
	t_process	*tmp;
	t_process	*next;
	t_process	*before;

	if (!*proc)
		return (1);
	tmp = *proc;
	next = tmp->next;
	if (id == tmp->id)
	{
		*proc = *ft_ff(&tmp, &next);
		return (1);
	}
	while (tmp)
	{
		if (tmp->id == id)
		{
			next = tmp->next;
			before->next = *ft_ff(&tmp, &next);
			return (1);
		}
		before = tmp;
		tmp = tmp->next;
	}
	return (1);
}
