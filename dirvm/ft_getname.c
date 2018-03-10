/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:20:05 by emerabet          #+#    #+#             */
/*   Updated: 2018/03/10 12:20:17 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void				*ft_getname(unsigned char *data, t_player *player)
{
	int				i;
	int				sizemagic;

	sizemagic = 4;
	i = sizemagic;
	while (i < PROG_NAME_LENGTH + sizemagic)
	{
		player->header.prog_name[i - sizemagic] = data[i];
		i++;
	}
}
