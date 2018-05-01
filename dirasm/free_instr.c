/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:25:31 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/05/01 15:40:51 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		free_instr(t_instr **instr)
{
	if (!*instr)
		return (0);
	while (*instr)
	{
		if (ft_strcmp((*instr)->cmd, "tmp"))
		{
			if ((*instr)->params)
				free_par(&(*instr)->params);
		}
		if ((*instr)->cmd)
		{
			free((*instr)->cmd);
			(*instr)->cmd =0;
		}
		if ((*instr)->label)
			free_lab(&(*instr)->label);
		free(*instr);
		*instr = (*instr)->next;
	}
	return (0);
}
