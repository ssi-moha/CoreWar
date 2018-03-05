/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:25:49 by emerabet          #+#    #+#             */
/*   Updated: 2018/03/05 19:47:56 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		ft_testhex(t_app *application)
{
	t_header	header;
	t_instr		*instructions;
	int out;

	out = open("xxxxxxx.cor", O_WRONLY | O_TRUNC | O_CREAT, 777);
	header = application->header;
	instructions = application->instr;
	
	printf("\n\n TEST WRITE HEADER\n");
//	write(out, &header.magic, sizeof(unsigned int));
	printf("HEXXXX %x\n", header.magic);
//	write(out, header.prog_name, sizeof(char * (PROG_NAME_LENGHT + 1)));
//	write(out, header.prog_size, sizeof(unsigned int));
//	write(out, header.comment, sizeof(char * (COMMENT_LENGTH + 1)));
//	write(out, application->header.comment, COMMENT_LENGTH + 1);
	write(out, &header, sizeof(t_header));
	write(out, "\0\0\0\0", 4);
	printf("%s\n", header.prog_name);
	printf("%s\n", header.comment);
	ft_printhex(instructions, out);
//	ft_converttohex(application->instr);
	return (0);
}
