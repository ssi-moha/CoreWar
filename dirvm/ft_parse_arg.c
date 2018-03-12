/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 16:20:59 by emerabet          #+#    #+#             */
/*   Updated: 2018/03/12 11:46:32 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static char		*ft_get_next_arg(char **argv, int argc, int key)
{
	if (key + 1 >= argc)
		return (NULL);
	return (argv[key + 1]);
}

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

static int		ft_check_champion(char **argv, int argc, t_args *args, int key)
{
	char	*str;
	char	*name;
	int		num;

	if (ft_strcmp(argv[key], "-n") == 0)
	{
		str = ft_get_next_arg(argv, argc, key);
		if (str != NULL)
		{
			name = ft_get_next_arg(argv, argc, key + 1);
			if (ft_check_filename(name, EXT_COR) == -1)
				return (-1);
			else
			{
				num = ft_atoi(str);
				if (num > 0)
					args->champion[args->nb] = num;
				else
					return (-2);
				args->nb = args->nb + 1;
				return (3);
			}
		}
		return (-1);
	}
	else
	{
		if (ft_check_filename(argv[key], EXT_COR) == 1)
		{
			args->champion[args->nb] = -1;
			args->nb = args->nb + 1;
			return (1);
		}
	}
	return (-1);
}

static void		ft_init_args(t_args *args)
{
	args->dump = -1;
	args->nb = 0;
	args->champion[0] = -9;
	args->champion[1] = -9;
	args->champion[2] = -9;
	args->champion[3] = -9;
	args->isvalid = 1;
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
		if (args.dump < 0)
		{
			args.dump = ft_hasdump(argc, argv, i, &args);
			if (args.dump >= 0)
			{
				i = i + 2;
				continue ;
			}
		}
		res = ft_check_champion(argv, argc, &args, i);
		if (res > 0)
		{
			i = i + res;
			continue ;
		}
		else
			break ;
		i++;
	}
	fprintf(stderr, "\n#### RESULT PARSING ARGS ###\n\n-dump = %d\n-n [0] => %d\n-n [1] => %d\n-n [2] => %d\n-n [3] => %d\nisvalid = %d\n\n", args.dump, args.champion[0], args.champion[1], args.champion[2], args.champion[3], args.isvalid);
	return (args);
}
