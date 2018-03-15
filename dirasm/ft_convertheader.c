/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertheader.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:23:31 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/15 14:47:33 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_printmagic(wchar_t magic, int out)
{
	unsigned char	m[4];
	int				i;

	i = 3;
	while (i >= 0)
	{
		m[i--] = magic % 256;
		magic = magic / 256;
	}
	i = 0;
	while (i < 4)
		write(out, &m[i++], 1);
}

static void	ft_printname(char name[PROG_NAME_LENGTH + 1], int out)
{
	int i;

	i = 0;
	while (i < PROG_NAME_LENGTH)
		write(out, &name[i++], 1);
	write(out, "\0\0\0\0", 4);
}

static void	ft_printcomment(char name[COMMENT_LENGTH + 1], int out)
{
	int i;

	i = 0;
	while (i < COMMENT_LENGTH)
		write(out, &name[i++], 1);
	write(out, "\0\0\0\0", 4);
}

int			ft_convertheader(t_app *application, char **file_name)
{
	t_header	header;
	t_instr		*instructions;
	int			out;
	char		*name;
	char		*cor;

	cor = ft_strjoin(*file_name, EXT_COR);
//	name = ft_strrchr(cor, '/');
	printf("name %s\n", cor);
	out = open(cor, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
//	lseek(out, 0, SEEK_SET);
	header = application->header;
	instructions = application->instr;
	ft_printmagic((wchar_t)(header.magic), out);
	ft_printname(header.prog_name, out);
	ft_printmagic(header.prog_size, out);
	ft_printcomment(header.comment, out);
	ft_printhex(instructions, out);
	close(out);
	ft_strdel(&cor);
	ft_strdel(file_name);
	return (0);
}
