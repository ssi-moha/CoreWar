/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:20:55 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/08 13:53:04 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static unsigned int		ft_count_positive(t_instr *tmp, t_instr **instr,
									char *label, int cmd)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (tmp && ft_strcmp(label, tmp->label))
	{
		i += tmp->sizeoctet;
		tmp = tmp->next;
	}
	if (tmp == 0)
		exit(error_mess("ERROR ILLEGAL LABEL\n"));
	j = (unsigned int)i;
	return (j);
}

static unsigned int		ft_count_negative(t_instr *tmp, t_instr **instr,
										int cmd)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (tmp && tmp != *instr)
	{
		i -= tmp->sizeoctet;
		tmp = tmp->next;
	}
	if (g_optab[cmd].dirsize == 1)
		j = 65536 + i;
	else
		j = 4294967296 + i;
	return (j);
}

unsigned int			count_label(t_instr **instr, t_instr **begin,
									char *label, int cmd)
{
	int				i;
	t_instr			*tmp;
	unsigned int	j;

	tmp = *begin;
	i = 0;
	while (tmp && tmp != *instr && ft_strcmp(label, tmp->label))
		tmp = tmp->next;
	if (tmp == *instr)
		j = ft_count_positive(tmp, instr, label, cmd);
	else if (!ft_strcmp(label, tmp->label))
		j = ft_count_negative(tmp, instr, cmd);
	else
		exit(error_mess("ERROR ILLEGAL LABEL\n"));
	return (j);
}
