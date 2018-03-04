/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_instr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:21:05 by ssi-moha          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/03 18:53:06 by lfujimot         ###   ########.fr       */
=======
/*   Updated: 2018/03/03 18:21:09 by ssi-moha         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

<<<<<<< HEAD
t_instr	*new_instr(char *cmd, t_instr **prev)
=======
void	new_instr(char *cmd, t_instr **prev)
>>>>>>> refs/remotes/origin/master
{
	t_instr *tmp;
	t_instr *tmp2;

	tmp = NULL;
	tmp2 = *prev;
	if (!(tmp = (t_instr*)malloc(sizeof(t_instr))))
<<<<<<< HEAD
		return (0);
=======
		return ;
>>>>>>> refs/remotes/origin/master
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
<<<<<<< HEAD
	return (tmp);
=======
>>>>>>> refs/remotes/origin/master
}
