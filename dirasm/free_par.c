/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_par.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:12:11 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/03 18:20:32 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		free_par(t_par **par)
{
	if (!*par)
		return (0);
	while (*par)
	{
		if ((*par)->par)
			free((*par)->par);
		free(*par);
		*par = (*par)->next;
	}
	return (0);
}
