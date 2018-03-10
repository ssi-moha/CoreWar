/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmagic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 10:01:29 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/10 11:13:47 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void	ft_checkmagic(unsigned char *data)
{
	int i;
	int magic;

	magic = COREWAR_EXEC_MAGIC;
	i = 3;
	while (i >= 0)
	{
		if (!(data[i] == (magic % 256)))
			exit(error_mess("ERROR WRONG MAGIC\n"));
		magic /= 256;
		i--;
	}
}
