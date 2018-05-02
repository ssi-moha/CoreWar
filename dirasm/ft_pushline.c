/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 15:55:04 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/02 19:21:37 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void		ft_pushline(t_l **li, char **line)
{
	t_l		*new;

	new = *li;
	if (new)
	{
		while (new->next)
			new = new->next;
		if (new)
		{
			new->next = (t_l *)malloc(sizeof(*new));
			if (!new)
				return ;
			new->li = *line;
			new->next = 0;
		}
	}
	else
	{
		*li = (t_l *)malloc(sizeof(*new));
		if (!*li)
			return ;
		(*li)->li = *line;
		(*li)->next = 0;
	}
}
