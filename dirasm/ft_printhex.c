/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 13:18:41 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/05 16:48:03 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_printcmd(char *cmd, int out)
{
	int c;

	c = ft_findcmd(cmd) + 1;
	write(out, c, 1);
}

void	ft_printhex(t_instr *instr, int out)
{
	t_instr *tmp;

	tmp = instr;
	while (tmp)
	{
//		ft_print(
		tmp = tmp->next;
	}	
}
