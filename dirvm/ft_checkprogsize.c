/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkprogsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 10:18:16 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/10 11:07:38 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void	ft_checkprogsize(unsigned char *data)
{
	int i;
	int nb;
	int decalage;

	decalage = 3;
	nb = 0;
	i = PROG_NAME_LENGTH + 4 + 4;
	while (i < PROG_NAME_LENGTH + 4 + 4 + 4)
	{
		nb = nb + (data[i] << (8 * decalage));
		decalage--;
		i++;
	}
	if (nb > CHAMP_MAX_SIZE)
		exit(error_mess("ERROR CHAMP TOO BIG FOR THE VM\n"));
}
