/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcomment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 12:03:39 by emerabet          #+#    #+#             */
/*   Updated: 2018/03/10 14:40:53 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void				ft_setcomment(unsigned char *data, t_header *header)
{
	int				i;
	int				sizemagic;
	int				temp;

	sizemagic = 4;
	temp = sizemagic + PROG_NAME_LENGTH + 4 + 4;
	i = temp;
	while (i < COMMENT_LENGTH + temp)
	{
		header->comment[i - temp] = data[i];
		i++;
	}
}
