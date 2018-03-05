/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 09:54:21 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/05 11:52:09 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_init(t_app *app)
{
	t_header h;
	h.magic = COREWAR_EXEC_MAGIC;
	h.prog_size = 0;
	app->instr = 0;
	app->header = h;
}

static void	ft_parseasm(t_instr **instr, int fd)
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
		if (ft_skip_com_and_blank(line))
			continue ;
		else if (line[0] == '.') //a completer
			continue ;
		printf("%s\n", line);
		new = new_instr("", instr); //mettre a 0
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
	t_app	app;
	int		fd;

	printf("%d\n", argc);
	if (argc < 2)
		exit (-1);
	ft_init(&app);
	fd = open(argv[1], O_RDONLY);
	ft_parseasm(&app.instr, fd);

	t_instr *tmp;
	tmp = app.instr;
	while (tmp)
	{
		printf("\nLABEL %s\n", tmp->label);
		printf("INSTR %s\n", tmp->cmd);
		t_par *p;
		p = tmp->params;
		while (p)
		{
			printf("PAR %s TYPE %d\n", p->par, p->type);
			p = p->next;
		}
		tmp = tmp->next;
	}
	int i = 0;
	while (i < 17)
	{
		printf("%s\n", g_optab[i].cmd);
		i++;
	}

		return (0);
}
