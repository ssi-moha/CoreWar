/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:48:57 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/14 14:16:36 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_initvm(t_vm *vm)
{
	vm->processes = 0;
	vm->players = 0;
	ft_bzero(vm->ram, MEM_SIZE);
	vm->curcycle = 0;
	vm->totalprocess = 0;
	vm->start = 1;
	vm->nblive = 0;
	vm->cyclelimit = CYCLE_TO_DIE;
}

int		main(int argc, char **argv)
{
	unsigned char	*data;
	unsigned int				i;
	t_vm			vm;
	t_player		*p;
	
//	if (argc < 2 || argc > 5)
//		exit(error_mess("ERROR NO PLAYER OR TOO MUCH PLAYER MUST BE BETWEEN 1 AND 4\n"));
	ft_initvm(&vm);
	vm.args = ft_parse_arg(argc, argv);
	if (vm.args.isvalid != 1)
		exit(error_mess("Wrong args\n"));
	i = -1;
	fprintf(stderr, "nb %d n1 =>%d\nn2 => %d\nn3 => %d\nn4 => %d\n", vm.args.nb, vm.args.champion[0], vm.args.champion[1], vm.args.champion[2], vm.args.champion[3]);
	while (++i < vm.args.nb)
	{
		if (ft_check_filename(argv[i], EXT_COR) == -1)
			continue ;
		data = ft_openfile(argv[i]);
		if (data != NULL)
		{
			p = new_player(data, &(vm.players), i, &vm);
			ft_checkmagic(data);
			ft_loadinram(data, vm.args.nb - 1, &vm, p); //attention argc -1 si autres paramettre
			new_process(p, &(vm.processes), &vm);
		}
	}
	ft_showram(vm.ram);
	
	t_process *tmp;
	tmp = vm.processes;
	while (tmp)
	{
		printf("PROCESS %2.2x", tmp->r[0][0]);
		printf("%2.2x", tmp->r[0][1]);
		printf("%2.2x", tmp->r[0][2]);
		printf("%2.2x\n", tmp->r[0][3]);
		tmp = tmp->next;
	}
	ft_startvm(&vm);
}
