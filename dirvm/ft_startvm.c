/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startvm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:13:43 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/14 17:04:29 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_loadinstructions(t_vm *vm)
{
	t_process	*tmp;

	tmp = vm->processes;
	while (tmp)
	{
		if (tmp->cycle == 0)
			ft_loadnewinstr(tmp, vm);
		tmp->cycle--;
		printf("PC %d CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCYCLE %d\n", tmp->pc, tmp->cycle);
		tmp = tmp->next;
	}
}

void	ft_startvm(t_vm *vm)
{
	printf("LIMIT %d\n", vm->cyclelimit);
	printf("CUR %d\n", vm->curcycle);
	while (vm->curcycle <= vm->cyclelimit)
	{
		if (vm->processes == 0)
		{
			printf("NO MORE PROCESSES\n");
			exit(2);
		}
		else
		{
			t_process *t;
			t = vm->processes;
			while (t)
			{
				printf("REG1 %3.2x %3.2x %3.2x %3.2x\n", vm->processes->r[0][0], vm->processes->r[0][1], vm->processes->r[0][2], vm->processes->r[0][3]);
				printf("REG2 %3.2x %3.2x %3.2x %3.2x\n", vm->processes->r[1][0], vm->processes->r[1][1], vm->processes->r[1][2], vm->processes->r[1][3]);
				printf("REG3 %3.2x %3.2x %3.2x %3.2x\n", vm->processes->r[2][0], vm->processes->r[2][1], vm->processes->r[2][2], vm->processes->r[2][3]);
				printf("REG6 %3.2x %3.2x %3.2x %3.2x\n", vm->processes->r[5][0], vm->processes->r[5][1], vm->processes->r[5][2], vm->processes->r[5][3]);
				t = t->next;
			}
		}
		if (vm->curcycle == vm->cyclelimit)
		{
			ft_checkinlive(&(vm->processes));
			//reset inlive de player a 0
			if (vm->nblive == 0)
				printf("GAME OVER\n");
			else if (vm->nblive < NBR_LIVE)
				vm->cyclelimit -= CYCLE_DELTA;
			vm->curcycle = 0;
		}
		else
		{
			ft_loadinstructions(vm);
			printf("CYCLE %d\n", vm->curcycle);
			vm->curcycle++;
		}
	}
}
