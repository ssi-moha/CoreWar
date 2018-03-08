/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 14:12:45 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/08 14:25:36 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		make_pos(int pos, char **line, t_instr *new, t_par *tmp)
{
	pos = ft_parselabel(*line, new);
	pos = ft_parseinstr(*line, pos, new);
	ft_parseparams(*line, pos, new);
	tmp = new->params;
	while (tmp)
		tmp = tmp->next;
	return (1);
}
