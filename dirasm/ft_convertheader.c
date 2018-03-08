/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:25:49 by emerabet          #+#    #+#             */
/*   Updated: 2018/03/08 16:56:08 by ssi-moha         ###   ########.fr       */
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

int			ft_convertheader(t_app *application)
{
	t_header	header;
	t_instr		*instructions;
	int			out;
	off_t		ret;
	int			clo;

	out = open("tes.cor", O_RDWR | O_APPEND | O_CREAT);
	ret = lseek(out, 0, SEEK_SET);
	header = application->header;
	instructions = application->instr;
	ft_printmagic((wchar_t)(header.magic), out);
	ft_printname(header.prog_name, out);
	ft_printmagic(header.prog_size, out);
	ft_printcomment(header.comment, out);
	ft_printhex(instructions, out);
	clo = close (out);
	return (0);
}
