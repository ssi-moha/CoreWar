/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 16:20:59 by emerabet          #+#    #+#             */
/*   Updated: 2018/04/25 16:41:21 by lfujimot         ###   ########.fr       */
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

static int		ft_hasvisu(int argc, char **argv, int key, t_args *args)
{
	if (ft_strcmp(argv[key], "-visu") != 0)
		return (-1);
	return (1);
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
				args->champion[args->nb] = num;
				args->posfile[args->nb] = key + 2;
				args->nb = args->nb + 1;
				fprintf(stderr, "KEY + 2: %d\n", key + 2);
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
			args->posfile[args->nb] = key;
			fprintf(stderr, "KEY : %d\n", key);
			args->nb = args->nb + 1;
			return (1);
		}
	}
	return (-1);
}

static void		ft_init_args(t_args *args)
{
	args->dump = -1;
	args->visu = -1;
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

void	ft_incpar(t_args *args)
{
	int i;

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
		if (args.visu < 0)
		{
			args.visu = ft_hasvisu(argc, argv, i, &args);
			if (args.visu >= 0)
			{
				i++;
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
		{
			args.isvalid = -1;
			break ;
		}
		i++;
	}
	ft_incpar(&args);
	fprintf(stderr, "\n#### RESULT PARSING ARGS ###\n\n-dump = %d\n-n [0] => %d\n-n [1] => %d\n-n [2] => %d\n-n [3] => %d\nisvalid = %d\n\n", args.dump, args.champion[0], args.champion[1], args.champion[2], args.champion[3], args.isvalid);
	return (args);
}
