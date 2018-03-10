/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:20:05 by emerabet          #+#    #+#             */
/*   Updated: 2018/03/10 13:17:20 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void				ft_setname(unsigned char *data, t_header *header)
{
	int				i;
	int				sizemagic;

	sizemagic = 4;
	i = sizemagic;
	while (i < PROG_NAME_LENGTH + sizemagic)
	{
		header->prog_name[i - sizemagic] = data[i];
		i++;
	}
}
