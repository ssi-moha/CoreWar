/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkparams.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:42:58 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/05 12:26:41 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static int	ft_checkparamtype(char *par)
{
	int dir;
	int i;
	int lab;

	lab = 0;
	i = 0;
	dir = 0;
	if (par)
	{
		if (par[i] == 'r')
		{
			i++;
			while (par[i])
			{
				if (ft_isdigit(par[i] == 0))
					return (-1); //erreur registre pas un nombre + check taille maximum du registre
				i++;
			}
			return (T_REG);
		}
		else 
		{
			if (par[i] == DIRECT_CHAR)
			{
				dir = 1;
				i++;
			}
			if (par[i] == LABEL_CHAR)
				lab = 1;
			else
			{
				if (par[i] == '-' || par[i] == '+')
					i++;
				while (par[i])
				{
					if (ft_isdigit(par[i] == 0))
						return (-1); //pas un valide car pas un nombre
					i++;
				}
			}
			if (dir == 1 && lab == 0)
				return (T_DIR);
			else if (dir == 1 && lab == 1)
				return (T_DIR + T_LAB);
			else if (dir == 0 && lab == 0)
				return (T_IND);
			else if (dir == 0 && lab == 1)
				return (T_IND + T_LAB);
		}
	}
	return (-1);
}

static int	ft_checkparamvalid(char *par)
{
	int i;

	if (par)
	{
		i = 0;
		if (par[i] == DIRECT_CHAR)
			i++;
		while (par[i] && (ft_isincharset(par[i], LABEL_CHARS) == 1 || par[i] == LABEL_CHAR ||  par[i] == DIRECT_CHAR ||  par[i] == '-'))
			i++;
		if (par[i] == '\0')
			return (1);
	}
	return (-1);
}

int			ft_checkparams(char *par)
{
	if (ft_checkparamvalid(par) == -1)
		return (-1);
	else
		return (ft_checkparamtype(par));
}
