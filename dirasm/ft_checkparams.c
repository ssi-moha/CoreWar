/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkparams.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:42:58 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/26 17:44:14 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static int	ft_check_type_except_register(char *par)
{
	int		i;
	int		lab;
	int		dir;

	i = 0;
	lab = 0;
	dir = 0;
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
			if (ft_isdigit(par[i++] == 0))
				return (-1);
		}
	}
	return (ft_type_value(dir, lab));
}

static int	ft_checkparamtype(char *par)
{
	int		i;

	i = 0;
	if (par)
	{
		if (par[i] == 'r')
		{
			i++;
			while (par[i])
			{
				if (ft_isdigit(par[i] == 0))
					return (-1);
				i++;
			}
			return (T_REG);
		}
		else
			return (ft_check_type_except_register(par));
	}
	return (-1);
}

static int	ft_ipar(char *par)
{
	if (par[0] == 'r')
		return (1);
	if (par[0] == DIRECT_CHAR)
		return (1);
	return (0);
}

static int	ft_checkparamvalid(char *par)
{
	int		i;

	if (par)
	{
		i = ft_ipar(par);
		if (par[i] == LABEL_CHAR)
		{
			i++;
			while (par[i] && (ft_isincharset(par[i], LABEL_CHARS) == 1))
				i++;
			if (par[i] == '\0')
				return (1);
		}
		else if (par[i] == '-' || par[i] == '+' ||
				(ft_isincharset(par[i], "0123456789") == 1))
		{
			if (par[i] == '-' || par[i] == '+')
				i++;
			while (par[i] && (ft_isincharset(par[i], "0123456789") == 1))
				i++;
			if (par[i] == '\0')
				return (1);
		}
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
