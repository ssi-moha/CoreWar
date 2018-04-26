/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpartype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:47:20 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/26 17:48:37 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_checkvalidchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isincharset(str[i], "0123456789") == -1)
			exit(error_mess("ERROR WRONG ARGS VALUE\n"));
		i++;
	}
}

int			ft_checkpartype(t_par *par, int parindex, char *cmd)
{
	int i;
	int type;
	int n;

	type = 0;
	i = ft_findcmd(cmd);
	if (i >= 0)
	{
		if (par->type == 1)
		{
			ft_checkvalidchar(par->par + 1);
			n = ft_atoi(par->par + 1);
			if (n <= 0 || n > REG_NUMBER)
				exit(error_mess("ERROR REGISTER DOES NOT EXIST\n"));
			type = 1;
		}
		else if (par->type == 2 || par->type == 10)
			type = 2;
		else if (par->type == 4 || par->type == 12)
			type = 4;
		if (!((g_optab[i].typepar[parindex] & type) == type))
			return (-1);
	}
	return (1);
}
