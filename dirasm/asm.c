/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 09:54:21 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/04 10:59:06 by lfujimot         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_instr	instr;
	int		fd;

	ft_init(&instr);
	fd = open(argv[1], O_RDONLY);
	ft_parseasm(&instr, fd);
	return (0);
}
