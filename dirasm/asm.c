/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:19:44 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/03 09:17:58 by emerabet         ###   ########.fr       */
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
	app->li = 0;
	app->header = h;
	ft_bzero(app->header.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(app->header.comment, COMMENT_LENGTH + 1);
	app->checkcmd = 0;
}

int				main(int argc, char **argv)
{
	t_app	app;
	int		fd;
	char	*file_name;

	if (argc != 2)
		exit(error_mess("ERROR : WRONG NUMBER OF ARGUMENT\n"));
	if (ft_check_filename(argv[1], EXT_FILE) == -1)
		exit(error_mess("ERROR : WRONG FILE NAME\n"));
	file_name = ft_strcdup(argv[1], '.');
	ft_init(&app);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(error_mess("ERROR : FILE CANNOT BE FOUND OR CANNOT BE OPENNED\n"));
	ft_parseasm(&app.instr, fd, &app.header, &app);
	ft_converttohex(&app.instr);
	app.header.prog_size = prog_size(&app.instr);
	if (app.instr == 0)
		exit(error_mess("NO PROGRAM TO CONVERT\n"));
	ft_convertheader(&app, &file_name);
	free_par(&app.instr->params);
	free_instr(&app.instr);
	ft_printffd(1, "file created for %s --> .cor\n", argv[1]);
	close(fd);
	return (0);
}
