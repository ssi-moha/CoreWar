/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:20:55 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/05 16:45:23 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		count_label(t_instr **instr, t_instr **begin, char *label)
{
	int i;
	int mark;
	t_instr *tmp;

	tmp = *begin;
	mark = 0;
	i = 0;
	while (tmp && tmp != *instr && !ft_strcmp(label, tmp->label))
	{
		tmp = tmp->next;
	}
	if (tmp == *instr)
		while (tmp && !ft_strcmp(label, tmp->label))
		{
			i -= tmp->sizeoctet;
			tmp = tmp->next;
		}
	else if (!ft_strcmp(label, tmp->label))
		while (tmp && !ft_strcmp(label, tmp->label))
		{
			i += tmp->sizeoctet;
			tmp = tmp->next;
		}
	else
		exit (error_mess(NULL));
	return (i);
}
