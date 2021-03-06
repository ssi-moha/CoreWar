/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isincharset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:21:23 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/05 09:21:32 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int	ft_isincharset(char c, char *charset)
{
	int i;

	i = 0;
	if (charset)
	{
		while (charset[i])
		{
			if (charset[i] == c)
				return (1);
			i++;
		}
	}
	return (-1);
}
