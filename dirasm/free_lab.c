/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 12:17:11 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/05/02 19:15:56 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		free_lab(t_lab **lab)
{
	t_lab *tmp;

	tmp = *lab;
	if (!*lab)
		return (0);
	while (*lab)
	{
		tmp = (*lab)->next;
		if ((*lab)->l)
		{
			free((*lab)->l);
			(*lab)->l = 0;
		}
		free(*lab);
		*lab = tmp;
	}
	return (0);
}
