/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:25:31 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/05/02 19:16:14 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		free_instr(t_instr **instr)
{
	t_instr	*tmp;

	tmp = 0;
	if (!*instr)
		return (0);
	while (*instr)
	{
		tmp = (*instr)->next;
		if (ft_strcmp((*instr)->cmd, "tmp"))
		{
			if ((*instr)->params)
				free_par(&(*instr)->params);
		}
		if ((*instr)->cmd)
		{
			free((*instr)->cmd);
			(*instr)->cmd = 0;
		}
		if ((*instr)->label)
			free_lab(&(*instr)->label);
		free(*instr);
		*instr = tmp;
	}
	return (0);
}
