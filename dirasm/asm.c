/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 09:54:21 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/04 16:40:18 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_init(t_instr *instr)
{
	instr->cmd = 0;
	instr->label = 0;
	instr->params = 0;
	instr->next = 0;
}

static void	ft_parseasm(t_instr *instr, int fd)
{
	char *line;
	int pos;
	t_instr *new;

	pos = 0;
	line = 0;
	while (get_next_line(fd, &line))
	{
		//	if (line[0] == '\n')
		//		continue ;
		printf("%s\n", line);
		new = new_instr("", &instr); //mettre a 0
		if (new)
		{
			pos = ft_parselabel(line, new);
			pos = ft_parseinstr(line, pos, new);
			ft_parseparams(line, pos, new);
			printf("LABEL %s\n", new->label);
			printf("CMD %s\n", new->cmd);
			t_par *tmp;
			tmp = new->params;
			while (tmp)
			{
				printf("PAR %s\n", tmp->par);
				tmp = tmp->next;
			}
		}
	}
}

static void ft_process(t_op op_tab[17], char **argv)
{
	t_instr	instr;
	int		fd;

	ft_init(&instr);
	fd = open(argv[1], O_RDONLY);
	ft_parseasm(&instr, fd);
	int i = -1;
		printf("%s\n", op_tab->cmd);

}

int	main(int argc, char **argv)
{
		t_op    op_tab[17] =
		{
			{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
			{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
			{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
			{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
			{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
			{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
				"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
			{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
				"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
			{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
				"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
			{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
			{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
				"load index", 1, 1},
			{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
				"store index", 1, 1},
			{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
			{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
			{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
				"long load index", 1, 1},
			{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
			{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
			{0}
		};
	ft_process(op_tab, argv);
		return (0);
}
