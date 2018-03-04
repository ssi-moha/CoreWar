/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:26:04 by lfujimot          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/03 19:12:08 by lfujimot         ###   ########.fr       */
=======
/*   Updated: 2018/03/03 17:51:15 by ssi-moha         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
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
			printf("%s\n", new->label);
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
