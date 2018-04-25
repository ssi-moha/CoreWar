/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_champion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 17:36:04 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/25 17:54:21 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

char		*ft_get_next_arg(char **argv, int argc, int key)
{
	if (key + 1 >= argc)
		return (NULL);
	return (argv[key + 1]);
}

int			ft_hasvisu(int argc, char **argv, int key, t_args *args)
{
	if (ft_strcmp(argv[key], "-visu") != 0)
		return (-1);
	return (1);
}

static int	ft_checkcor(char **argv, int argc, t_args *args, int key)
{
	char	*str;
	char	*name;
	int		num;

	str = ft_get_next_arg(argv, argc, key);
	if (str != NULL)
	{
		name = ft_get_next_arg(argv, argc, key + 1);
		if (ft_check_filename(name, EXT_COR) == -1)
			return (-1);
		else
		{
			num = ft_atoi(str);
			args->champion[args->nb] = num;
			args->posfile[args->nb] = key + 2;
			args->nb = args->nb + 1;
			return (3);
		}
	}
	return (-1);
}

int			ft_check_champion(char **argv, int argc, t_args *args, int key)
{
	if (ft_strcmp(argv[key], "-n") == 0)
		return (ft_checkcor(argv, argc, args, key));
	else
	{
		if (ft_check_filename(argv[key], EXT_COR) == 1)
		{
			args->champion[args->nb] = -1;
			args->posfile[args->nb] = key;
			args->nb = args->nb + 1;
			return (1);
		}
	}
	return (-1);
}
