/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:03:59 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/21 19:14:09 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

t_lab	*new_label(char *l, t_lab **prev)
{
	t_lab *tmp;
	t_lab *tmp2;

	tmp = NULL;
	tmp2 = *prev;
	if (!(tmp = (t_lab*)malloc(sizeof(t_lab))))
		return (0);
	if (l)
		tmp->l = ft_strdup(l);
	else
		tmp->l = NULL;
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
