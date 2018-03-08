/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 09:54:21 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/08 14:26:53 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void		ft_init(t_app *app)
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

static void		ft_parseasm(t_instr **instr, int fd, t_header *head, t_app *app)
{
	char	*line;
	int		pos;
	t_instr	*new;
	int		ret;
	t_par	*tmp;

	ret = 0;
	pos = 0;
	line = 0;
	while (get_next_line(fd, &line))
	{
		if (ft_skip_com_and_blank(line))
		{
			ft_strdel(&line);
			continue ;
		}
		else if ((ret = check_name_cmt(line)))
		{
			app->checkcmd += cpy_head(ret, head, &line);
			continue ;
		}
		if (app->checkcmd != 2)
			exit(error_mess("ERROR NO .NAME OR NO .COMMENT\n"));
		new = new_instr(NULL, instr);
		if (new)
			make_pos(pos, &line, new, tmp);
		ft_strdel(&line);
	}
}

static int		ft_checkfilename(char *name)
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

int				main(int argc, char **argv)
{
	t_app	app;
	int		fd;
	int		j;
	t_par	*p;
	t_instr *tmp;

	if (argc < 2)
		exit(error_mess("ERROR : WRONG NUMBER OF ARGUMENT\n"));
	if (ft_checkfilename(argv[1]) == 0)
		exit(error_mess("ERROR : WRONG FILE NAME\n"));
	ft_init(&app);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(error_mess("ERROR : FILE CANNOT BE FOUD OR CANNOT BE OPENNED\n"));
	ft_parseasm(&app.instr, fd, &app.header, &app);
	tmp = app.instr;
	ft_converttohex(app.instr);
	app.header.prog_size = prog_size(&app.instr);
	ft_testhex(&app);
	free_par(&app.instr->params);
	free_instr(&app.instr);
	return (0);
}
