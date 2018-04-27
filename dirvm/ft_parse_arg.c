/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 16:20:59 by emerabet          #+#    #+#             */
/*   Updated: 2018/04/27 11:46:43 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static int		ft_hasdump(int argc, char **argv, int key, t_args *args)
{
	int		cycle;
	char	*str;

	cycle = -1;
	if (ft_strcmp(argv[key], "-dump") != 0)
		return (-1);
	str = ft_get_next_arg(argv, argc, key);
	if (str == NULL)
	{
		args->isvalid = -1;
		return (-2);
	}
	cycle = ft_atoi(argv[key + 1]);
	return (cycle);
}

static void		ft_init_args(t_args *args)
{
	args->dump = -1;
	args->visu = -1;
	args->verb = -1;
	args->live = -1;
	args->nb = 0;
	args->champion[0] = -9;
	args->champion[1] = -9;
	args->champion[2] = -9;
	args->champion[3] = -9;
	args->isvalid = 1;
	args->posfile[0] = -1;
	args->posfile[1] = -1;
	args->posfile[2] = -1;
	args->posfile[3] = -1;
}

void			ft_incpar(t_args *args)
{
	int i;

	if (args->champion[0] == -1)
		args->champion[0] = 1;
	i = 1;
	while (i < 4)
	{
		if (args->champion[i] == -1)
		{
			args->champion[i] = args->champion[i - 1] + 1;
		}
		i++;
	}
}

static int		ft_flags(int argc, char **argv, int i, t_args *args)
{
	if (args->dump < 0)
	{
		args->dump = ft_hasdump(argc, argv, i, args);
		if (args->dump >= 0)
			return (i + 2);
	}
	if (args->visu < 0)
	{
		args->visu = ft_hasvisu(argv, i);
		if (args->visu >= 0)
			return (i + 1);
	}
	if (args->verb < 0)
	{
		args->verb = ft_hasverb(argv, i);
		if (args->verb >= 0)
			return (i + 1);
	}
	if (args->live < 0)
	{
		args->live = ft_haslive(argv, i);
		if (args->live >= 0)
			return (i + 1);
	}
	return (i);
}

t_args			ft_parse_arg(int argc, char **argv)
{
	t_args		args;
	int			i;
	int			res;

	i = 1;
	ft_init_args(&args);
	while (i < argc && args.isvalid == 1)
	{
		i = ft_flags(argc, argv, i, &args);
		res = ft_check_champion(argv, argc, &args, i);
		if (res > 0)
		{
			i = i + res;
			continue ;
		}
		else
		{
			args.isvalid = -1;
			break ;
		}
	}
	ft_incpar(&args);
	return (args);
}
