/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:25:31 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/04/24 15:06:53 by ssi-moha         ###   ########.fr       */
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
			if ((*instr)->cmd)
				free((*instr)->cmd);
			if ((*instr)->label)
				free((*instr)->label);
			if ((*instr)->params)
				free_par(&(*instr)->params);
		}
		free(*instr);
		*instr = (*instr)->next;
	}
	return (0);
}
