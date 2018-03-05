/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 14:25:49 by emerabet          #+#    #+#             */
/*   Updated: 2018/03/05 14:29:27 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		ft_testhex(t_app *application)
{
	t_header	header;
	t_instr		*instructions;

	header = application.header;
	t_instr = application->instr;

	printf("\n\n TEST WRITE HEADER\n");
	write(1, &header, sizeof(t_header));
}
