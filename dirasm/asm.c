/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 09:54:21 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/11 15:51:24 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void		ft_init(t_app *app)
{
	t_header h;

	h.magic = COREWAR_EXEC_MAGIC;
	h.prog_size = 0;
	app->instr = 0;
	app->tmplab = 0;
	app->header = h;
	ft_bzero(app->header.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(app->header.comment, COMMENT_LENGTH + 1);
	app->checkcmd = 0;
}

static void		ft_parseasm(t_instr **instr, int fd, t_header *head, t_app *app)
{
	char	*line;
	t_instr	*new;
	int		ret;
	t_par	*tmp;

	ret = 0;
	line = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_skip_com_and_blank(line))
		{
			ft_strdel(&line);
			continue ;
		}
		else if (ft_labonly(app, line) == 1)
			continue ;
		else if ((ret = check_name_cmt(line)))
		{
			app->checkcmd += cpy_head(ret, head, &line);
			continue ;
		}
		if (app->checkcmd != 2)
			exit(error_mess("ERROR NO .NAME OR NO .COMMENT\n"));
		new = new_instr(NULL, instr);
		new != NULL ? make_pos(&line, new, tmp) : 0;
		if (app->tmplab != 0)
		{
			t_lab *t;

			t = app->tmplab;
			while (t)
			{
				new_label(ft_strdup(t->l), &(new->label));
				t = t->next;
			}
		}
	//	new->label = app->tmplab;
		app->tmplab = 0;//to free
		ft_strdel(&line);
	}
}

int				main(int argc, char **argv)
{
	t_app	app;
	int		fd;
	char *file_name;
	t_par	*p;
	t_instr *tmp;

	if (argc < 2)
		exit(error_mess("ERROR : WRONG NUMBER OF ARGUMENT\n"));
	if (ft_check_filename(argv[1], EXT_FILE) == -1)
		exit(error_mess("ERROR : WRONG FILE NAME\n"));
	file_name = ft_strcdup(argv[1], '.');
	ft_init(&app);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(error_mess("ERROR : FILE CANNOT BE FOUND OR CANNOT BE OPENNED\n"));
	ft_parseasm(&app.instr, fd, &app.header, &app);
	tmp = app.instr;
	t_instr *t;
	t = tmp;
	while (t)
	{
		printf("C\n");
		if (t->label)
			printf("t %s\n", t->label->l);
		t = t->next;
	}

	ft_converttohex(app.instr);
	app.header.prog_size = prog_size(&app.instr);
	if (app.instr == 0)
		exit(error_mess("NO PROGRAM TO CONVERT\n"));
	
	ft_convertheader(&app, &file_name);
	free_par(&app.instr->params);
	free_instr(&app.instr);
	close(fd);
	return (0);
}
