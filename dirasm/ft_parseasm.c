/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseasm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:51:48 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/02 16:30:21 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

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

static void		ft_copy_label(t_app **app, t_instr **new, char **line,
		t_instr **instr)
{
	t_lab *t;
	
	*new = new_instr(NULL, instr);
	*new != NULL ? make_pos(line, *new) : 0;
	t_instr *l;
	l = (*app)->instr;
	if ((*app)->tmplab != 0)
	{
		t = (*app)->tmplab;
		while (t)
		{
			new_label(t->l, &((*new)->label));
			t = t->next;
		}
	}
//	free_lab(&(app->tmplab));
//	app->tmplab = 0;
	//ft_pushline(&(app->li), line);	
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
	char *tmp;
	
	if (*line && cnt_char(line, '"') > 2)
		exit(error_mess("INVALID .NAME OR NO .COMMENT\n"));
	while (*line && cnt_char(line, '"') != 2)
	{
		tmp = *line;
		*line = join_lines(fd, line);
		ft_strdel(&tmp);
		if (*line == 0)
			exit(error_mess("ERROR NO .NAME OR NO .COMMENT\n"));
	}
}

void			ft_parseasm(t_instr **instr, int fd, t_header *head, t_app *app)
{
	char	*line;
	t_instr	*new;
	int		ret;

	ft_initparseasm(&line, &ret, &new);
	while (get_next_line(fd, &line))
	{
		if (ft_skip_com_and_blank(&line))
			ft_strdel(&line);
		else if (ft_labonly(&app, &line) == 1)
			ft_strdel(&line);
		else if ((ret = check_name_cmt(&line)))
		{
			ft_join(fd, &line);
			app->checkcmd += cpy_head(ret, head, &line);
			ft_strdel(&line);
		}
		else if (app->checkcmd != 2)
			exit(error_mess("ERROR NO .NAME OR NO .COMMENT\n"));
		else
			ft_copy_label(&app, &new, &line, instr);
	//	ft_strdel(&line);
	}
	ft_lastlab(instr, app, new);
}
