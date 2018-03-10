/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:48:57 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/10 11:45:20 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_initvm(t_vm *vm)
{
	ft_bzero(vm->ram, MEM_SIZE);
}

int		main(int argc, char **argv)
{
	unsigned char	*data;
	int				i;
	t_vm			vm;

	if (argc < 2 || argc > 5)
		exit(error_mess("ERROR NO PLAYER OR TOO MUCH PLAYER MUST BE BETWEEN 1 AND 4\n"));
	i = 1;
	ft_initvm(&vm);
	while (i < argc)
	{
		if (ft_check_filename(argv[1], EXT_COR) == -1)
			exit(error_mess("Wrong filename\n"));
		data = ft_openfile(argv[1]);
		if (data != NULL)
		{
			ft_checkmagic(data);
			ft_checkprogsize(data);
			ft_getname(data);
		}
		ft_loadinram(data, i, argc - 1, &vm);
		i++;
	}
}
