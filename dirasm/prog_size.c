/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:51:01 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/08 13:55:22 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		prog_size(t_instr **instr)
{
	t_instr *tmp;
	int		i;

	i = 0;
	if (!*instr)
		return (0);
	tmp = *instr;
	while (tmp)
	{
		i += tmp->sizeoctet;
		tmp = tmp->next;
	}
	return (i);
}
