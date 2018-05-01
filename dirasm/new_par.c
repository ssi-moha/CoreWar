/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_par.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:53:55 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/05/01 16:12:43 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

t_par	*new_par(char *par, t_par **prev)
{
	t_par *tmp;
	t_par *tmp2;

	tmp = NULL;
	tmp2 = *prev;
	if (!(tmp = (t_par*)malloc(sizeof(t_par))))
		return (0);
	if (par)
		tmp->par = ft_strdup(par);
	else
		tmp->par = NULL;
	tmp->next = NULL;
	tmp->type = 0;
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
