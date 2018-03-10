/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getname.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:20:05 by emerabet          #+#    #+#             */
/*   Updated: 2018/03/10 12:01:16 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

unsigned char		*ft_getname(unsigned char *data)
{
	unsigned char	*name;
	int				i;
	int				sizemagic;

	name = (unsigned char *)ft_strnew(PROG_NAME_LENGTH);
	if (name == NULL)
		return (NULL);
	sizemagic = 4;
	i = sizemagic;
	while (i < PROG_NAME_LENGTH + sizemagic)
	{
		name[i - sizemagic] = data[i];
		i++;
	}
	return (name);
}
