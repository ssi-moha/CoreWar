/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:20:55 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/08 10:51:25 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

unsigned int		count_label(t_instr **instr, t_instr **begin, char *label, int cmd)
{
	int i;
	int mark;
	t_instr *tmp;
	unsigned int j;

	tmp = *begin;
	mark = 0;
	i = 0;

	while (tmp && tmp != *instr && ft_strcmp(label, tmp->label))
		tmp = tmp->next;
	if (tmp == *instr)
	{
		while (tmp && ft_strcmp(label, tmp->label))
		{
			i += tmp->sizeoctet;
			tmp = tmp->next;
		}
		if (tmp == 0)
			exit(error_mess("ERROR ILLEGAL LABEL\n"));
		j = (unsigned int)i;
	}
	else if (!ft_strcmp(label, tmp->label))
	{
		while (tmp && tmp != *instr)
		{
			i -= tmp->sizeoctet;
			tmp = tmp->next;
		}
		if (g_optab[cmd].dirsize == 1)
			j = 65536 + i;
		else
			j = 4294967296 + i;
	}
	else
		exit (error_mess("ERROR ILLEGAL LABEL\n"));
	return (j);
}
