/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:48:57 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/10 12:52:58 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_initvm(t_vm *vm)
{
	vm->processes = 0;
	vm->players = 0;
	ft_bzero(vm->ram, MEM_SIZE);
	vm->curcycle = 0;
	vm->cyclelimit = CYCLE_TO_DIE;
}

int		main(int argc, char **argv)
{
	unsigned char	*data;
	int				i;
	t_vm			vm;
	t_player		*p;
	
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
			p = new_player(data, &(vm.players), i);
			ft_checkmagic(data);
			ft_loadinram(data, argc - 1, &vm, p);
		}
		i++;
	}
	int j;

	j = 0;
	int n;
	n = 0;
	while (j < MEM_SIZE)
	{
		printf("%3.2x", vm.ram[j]);
		if (n == 64)
		{
			printf("\n");
			n = -1;
		}
		n++;
		j++;
	}
}
