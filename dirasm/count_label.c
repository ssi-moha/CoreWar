/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:20:55 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/07 16:41:48 by lfujimot         ###   ########.fr       */
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

		printf("lllll %s\n", tmp->cmd);
		printf("lllll %s\n", (*instr)->cmd);
	while (tmp && tmp != *instr && ft_strcmp(label, tmp->label))
	{
		printf("lllllkkkk %s\n", tmp->cmd);
		tmp = tmp->next;
	}
	if (tmp == *instr)
	{
		printf("IIIIIIIIIIIIIIIIIIIIII\n");
		while (tmp && ft_strcmp(label, tmp->label))
		{
			printf("hhhh %s\n", tmp->cmd);
			i += tmp->sizeoctet;
			tmp = tmp->next;
		}
		printf("le i : %d\n", i);
		j = (unsigned int)i;
	}
	else if (!ft_strcmp(label, tmp->label))
	{
		while (tmp && tmp != *instr)
		{
			printf("ggggg\n");
			i -= tmp->sizeoctet;
			tmp = tmp->next;
		}
		if (g_optab[cmd].dirsize == 1)
			j = 65536 + i;
		else
			j = 4294967296 + i;
	}
	else
		exit (error_mess(NULL));
	printf("J %u I %d\n", j, i);
	return (j);
}
