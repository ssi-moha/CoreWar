/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findcmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 12:05:41 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/08 13:56:42 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		ft_findcmd(char *cmd)
{
	int i;

	i = 0;
	while (i < 17)
	{
		if (ft_strcmp(cmd, g_optab[i].cmd) == 0)
			return (i);
		i++;
	}
	return (-1);
}
