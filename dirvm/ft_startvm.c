/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startvm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 15:13:43 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/25 15:12:01 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_loadinstructions(t_vm *vm)
{
	t_process	*tmp;

	tmp = vm->processes;
	while (tmp)
	{
//	fprintf(stderr, "ICII %u %d ID %d\n", tmp->cmd, tmp->cycle, tmp->id);
//		printf("\x1b[34mPROCESS %d\n\x1b[0m", tmp->id);
		if (tmp->cycle == 0)
			ft_loadnewinstr(tmp, vm);
		tmp->cycle--;
//		printf("PC %d CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCYCLE %d\n", tmp->pc, tmp->cycle);
		tmp = tmp->next;
	}
}

void	ft_startvm(t_vm *vm)
{
	int fd;
	int out;

//	printf("LIMIT %d\n", vm->cyclelimit);
			//printf("YES\n");

	while (vm->curcycle <= vm->cyclelimit)
	{
	//	printf("CUR %d\n", vm->curcycle);
		printf("C %d CUR %d CYCLE TO DIE %d NBLIVE %d\n", vm->curcycle, vm->cycletotal, vm->cyclelimit, vm->nblive);

		if (vm->args.visu == 1)
		{
		if ((fd = open("OUTPUT.txt", O_RDONLY)) < 0)
		{
			close(fd);
			printf("FDD %d\n", fd);
			
			ft_showramplayer(vm->ramplayer, vm);
		}
		else
		{
			while ((fd = open("OUTPUT.txt", O_RDONLY)) > 0)
			{
//			printf("FD %d\n", fd);
				if (fd < 0)
				{
					close(fd);
					ft_showramplayer(vm->ramplayer, vm);
				}
				close(fd);
			}
	//		t_process *p = vm->processes;
	//		while (p)
	//		{
	//			printf("prod %d\n", p->num);
	//			p = p->next;
	//		}t_player *pp = vm->players;
	//		while (pp)
	//		{
	//			printf("prodddd %d\n", pp->num);
	//			pp = pp->next;
	//		}

		}}
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
//				printf("REG1 %3.2x %3.2x %3.2x %3.2x\n", vm->processes->r[0][0], vm->processes->r[0][1], vm->processes->r[0][2], vm->processes->r[0][3]);
//				printf("REG2 %3.2x %3.2x %3.2x %3.2x\n", vm->processes->r[1][0], vm->processes->r[1][1], vm->processes->r[1][2], vm->processes->r[1][3]);
//				printf("REG3 %3.2x %3.2x %3.2x %3.2x\n", vm->processes->r[2][0], vm->processes->r[2][1], vm->processes->r[2][2], vm->processes->r[2][3]);
//				printf("REG4 %3.2x %3.2x %3.2x %3.2x\n", vm->processes->r[3][0], vm->processes->r[3][1], vm->processes->r[3][2], vm->processes->r[3][3]);
//				printf("REG6 %3.2x %3.2x %3.2x %3.2x\n", vm->processes->r[5][0], vm->processes->r[5][1], vm->processes->r[5][2], vm->processes->r[5][3]);
				t = t->next;
			}
		}
		if (vm->curcycle == vm->cyclelimit)
		{
			ft_checkinlive(&(vm->processes), vm);
			ft_resetplayerinlive(&(vm->players));
			if (vm->nblive == 0 || vm->cyclelimit < CYCLE_DELTA)
			{
				ft_winner(vm);
				printf("GAME OVER\n");
				exit(2);
			}
			else if (vm->nblive >= NBR_LIVE)
			{
				vm->cyclelimit -= CYCLE_DELTA;
				vm->maxchecks = 0;
			}
			else
				vm->maxchecks++;
			if (vm->maxchecks >= MAX_CHECKS)
			{
				vm->cyclelimit -= CYCLE_DELTA;
				vm->maxchecks = 0;
			}
			vm->nblive = 0;
			vm->curcycle = 0;
		}
		else
		{
			ft_loadinstructions(vm);
//			printf("CYCLE %d\n", vm->curcycle);
			vm->curcycle++;
			vm->cycletotal++;
//			printf("PC TOTAL %d\n", vm->cycletotal);
		}
	}
}
