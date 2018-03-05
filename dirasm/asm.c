/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 09:54:21 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/05 10:31:58 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_init(t_app *app)
{
	app->instr = 0;
	app->name[0] = '\0';
	app->comment[0] = '\0';
	app->op = 0;
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
		if (line[0] == '\0')
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

static void	ft_initoptab()
{
	
}

int	main(int argc, char **argv)
{
	t_app	app;
	int		fd;

	ft_init(&app);
	fd = open(argv[1], O_RDONLY);
	ft_parseasm(&app.instr, fd);

	t_instr *tmp;
	tmp = app.instr;
	while (tmp)
	{
		printf("INSTR %s\n", tmp->cmd);
		tmp = tmp->next;
	}
	int i = 0;
//	while (g_optab[i])
//	{
		printf("%s\n", g_optab[i].cmd);
//		i++;
//	}

		return (0);
}
