/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:48:57 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/03 09:09:10 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_initvm(t_vm *vm)
{
	vm->processes = 0;
	vm->players = 0;
	ft_bzero(vm->ram, MEM_SIZE);
	ft_bzero(vm->ramplayer, MEM_SIZE);
	vm->curcycle = 0;
	vm->cycletotal = 0;
	vm->totalprocess = 0;
	vm->maxchecks = 0;
	vm->start = 1;
	vm->incplayer = 1;
	vm->nblive = 0;
	vm->lastlive = INT_MIN;
	vm->cyclelimit = CYCLE_TO_DIE;
}

int			main(int argc, char **argv)
{
	unsigned char	*data;
	int				i;
	t_vm			vm;
	t_player		*p;

	if (argc < 2)
		exit(error_mess("Wrong args\n"));
	ft_initvm(&vm);
	vm.args = ft_parse_arg(argc, argv);
	if (vm.args.isvalid == -1)
		exit(error_mess("Wrong args\n"));
	i = -1;
	while (++i < vm.args.nb)
	{
		data = ft_openfile(argv[vm.args.posfile[i]]);
		if (data != NULL)
		{
			p = new_player(data, &(vm.players), i, &vm);
			ft_checkmagic(data);
			ft_loadinram(data, vm.args.nb, &vm, p);
			new_process(p, &vm);
		}
		free(data);
	}
	ft_startvm(&vm);
}
