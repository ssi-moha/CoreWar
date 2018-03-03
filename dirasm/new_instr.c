/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_instr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:21:05 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/03 18:53:06 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

t_instr	*new_instr(char *cmd, t_instr **prev)
{
	t_instr *tmp;
	t_instr *tmp2;

	tmp = NULL;
	tmp2 = *prev;
	if (!(tmp = (t_instr*)malloc(sizeof(t_instr))))
		return (0);
	tmp->cmd = ft_strdup(cmd);
	tmp->label = NULL;
	tmp->params = NULL;
	tmp->next = NULL;
	if (!*prev)
		*prev = tmp;
	else
	{
		while (tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
	}
	return (tmp);
}
