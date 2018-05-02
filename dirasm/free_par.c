/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_par.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:12:11 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/05/02 15:51:51 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		free_par(t_par **par)
{
	t_par	*tmp;

	tmp = 0;
	if (!*par)
		return (0);
	while (*par)
	{
		tmp = (*par)->next;
		if ((*par)->par)
			ft_strdel(&(*par)->par);
		free(*par);
		*par = tmp;
	}
	return (0);
}
