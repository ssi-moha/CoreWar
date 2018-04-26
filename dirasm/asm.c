/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:19:44 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/26 15:49:20 by lfujimot         ###   ########.fr       */
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

static void		ft_lastlab(t_instr **instr, t_app *app, t_instr *new)
{
	t_lab		*p;

	p = app->tmplab;
	if (p)
	{
		new = new_instr("tmp", instr);
		new->label = app->tmplab;
	}
}

static void		ft_copy_label(t_app *app, t_instr **new, char **line,
		t_instr **instr)
{
	t_lab *t;

	*new = new_instr(NULL, instr);
	*new != NULL ? make_pos(line, *new) : 0;
	if (app->tmplab != 0)
	{
		t = app->tmplab;
		while (t)
		{
			new_label(t->l, &((*new)->label));
			t = t->next;
		}
	}
	app->tmplab = 0;
	ft_strdel(line);
}

static void		ft_initparseasm(char **line, int *ret, t_instr **new)
{
	*ret = 0;
	*line = 0;
	*new = NULL;
}

static void		ft_join(int fd, char **line)
{
	while (cnt_char(*line, '"') != 2)
	{
		*line = join_lines(fd, *line);
		if (line == 0)
			exit(error_mess("ERROR NO .NAME OR NO .COMMENT\n"));
	}
}

static void		ft_parseasm(t_instr **instr, int fd, t_header *head, t_app *app)
{
	char	*line;
	t_instr	*new;
	int		ret;

	ft_initparseasm(&line, &ret, &new);
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
			ft_join(fd, &line);
			app->checkcmd += cpy_head(ret, head, &line);
			continue ;
		}
		if (app->checkcmd != 2)
			exit(error_mess("ERROR NO .NAME OR NO .COMMENT\n"));
		ft_copy_label(app, &new, &line, instr);
	}
	ft_lastlab(instr, app, new);
}

int				main(int argc, char **argv)
{
	t_app	app;
	int		fd;
	char	*file_name;

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
	ft_converttohex(app.instr);
	app.header.prog_size = prog_size(&app.instr);
	if (app.instr == 0)
		exit(error_mess("NO PROGRAM TO CONVERT\n"));
	ft_convertheader(&app, &file_name);
	free_par(&app.instr->params);
	free_instr(&app.instr);
	ft_printf("file created %s.cor\n", app.header.prog_name);
	close(fd);
	return (0);
}
