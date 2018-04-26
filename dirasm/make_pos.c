/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:12:45 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/04/26 15:33:50 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		make_pos(char **line, t_instr *new)
{
	int		pos;
	t_par	*tmp;

	pos = 0;
	pos = ft_parselabel(*line, new);
	pos = ft_parseinstr(*line, pos, new);
	if (*line && pos < (int)ft_strlen(*line))
	{
		ft_parseparams(*line, pos, new);
		tmp = new->params;
		while (tmp)
			tmp = tmp->next;
	}
	return (1);
}
