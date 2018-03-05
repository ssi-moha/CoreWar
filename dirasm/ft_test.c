/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:25:49 by emerabet          #+#    #+#             */
/*   Updated: 2018/03/05 19:14:24 by lfujimot         ###   ########.fr       */
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
//	write(out, application->header.comment, COMMENT_LENGTH + 1);
	write(out, &header, sizeof(t_header));
	printf("%s\n", header.prog_name);
	printf("%s\n", header.comment);
	ft_printhex(instructions, out);
//	ft_converttohex(application->instr);
	return (0);
}
