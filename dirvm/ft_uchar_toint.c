/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uchar_toint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 14:46:14 by emerabet          #+#    #+#             */
/*   Updated: 2018/03/12 16:02:29 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		ft_uchar_toint(unsigned char tab[REG_SIZE])
{
	int		i;
	int		value;
	int		decalage;
	int		len;

	len = REG_SIZE - 1;
	decalage = (len) * 8;
	value = 0;
	i = 0;
	while (i < len)
	{
		value += tab[i] << decalage;
		fprintf(stderr, "i=%d  value=%d\n", i, value);
		decalage = decalage - 8;
		i++;
	}
	return (value);
}
