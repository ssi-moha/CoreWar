/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 09:54:21 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/07 18:36:20 by lfujimot         ###   ########.fr       */
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
	ft_bzero(app->header.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(app->header.comment, COMMENT_LENGTH + 1);
	app->checkcmd = 0;
}

static void	ft_parseasm(t_instr **instr, int fd, t_header *head, t_app *app)
{
	char *line;
	int pos;
	t_instr *new;
	int ret;

	ret = 0;
	pos = 0;
	line = 0;
	while (get_next_line(fd, &line))
	{
		//	if (line[0] == '\n')
		//		continue ;
		if (ft_skip_com_and_blank(line))
		{
			ft_strdel(&line);
			continue ;
		}
		if ((ret = check_name_cmt(line)))
		{
			app->checkcmd++;
			if (ret == 1)
				ft_strncpy(head->prog_name, ft_strchr(line, '"') + 1 , ft_strclen(ft_strchr(line, '"') + 1, '"'));
			else if (ret == 2)
				ft_strncpy(head->comment, ft_strchr(line, '"') + 1 , ft_strclen(ft_strchr(line, '"') + 1, '"'));
			ft_strdel(&line);
			continue ;
		}
		printf("%s\n", line);
		if (app->checkcmd != 2)
			exit(error_mess("ERROR NO .NAME OR NO .COMMENT\n"));
		new = new_instr(NULL, instr); //mettre a 0
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
		ft_strdel(&line);
	}
}

static int	ft_checkfilename(char *name)
{
	int size;

	size = 0;
	if (name)
	{
		size = ft_strlen(name);
		if (size > 2)
		{
			if (name[size - 1] == 's' && name[size - 2] == '.')
				return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_app	app;
	int		fd;
	int j;
	t_par *p;

	printf("%d\n", argc);
	if (argc < 2)
		exit (-1);
	if (ft_checkfilename(argv[1]) == 0)
		exit(error_mess("ERROR WRONG FILE NAME\n"));
	ft_init(&app);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(error_mess("ERROR FILE CANNOT BE FOUD OR CANNOT BE OPENNED\n"));
	ft_parseasm(&app.instr, fd, &app.header, &app);

	t_instr *tmp;
	tmp = app.instr;
	ft_converttohex(app.instr);
	app.header.prog_size = prog_size(&app.instr);
	ft_testhex(&app);	
	while (tmp)
	{
		printf("\nLABEL %s\n", tmp->label);
		printf("INSTR %s SIZE %u \n", tmp->cmd, tmp->sizeoctet);
		p = tmp->params;
		while (p)
		{
			printf("PAR %s TYPE %d\n", p->par, p->type);
			p = p->next;
		}
		tmp = tmp->next;
	}
	j = 0;
	printf("\n");
	while (j < COMMENT_LENGTH + 1)
		printf("%c", app.header.comment[j++]);
	printf("\n");
	free_par(&app.instr->params);
	free_instr(&app.instr);
	return (0);
}
