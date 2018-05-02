/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseinstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:11:04 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/02 15:45:26 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void		ft_copycmd(char *line, int start, int newpos, t_instr *instr)
{
	int	i;

	if (instr == 0)
		return ;
	instr->cmd = ft_strnew(newpos - start);
	if (instr->cmd == 0)
		return ;
	i = 0;
	while (start < newpos)
	{
		instr->cmd[i] = line[start];
		start++;
		i++;
	}
	instr->cmd[i] = '\0';
//	ft_printf("CMD %s\n", instr->cmd);
}

int				ft_parseinstr(char *line, int pos, t_instr *new)
{
	size_t	newpos;
	int		start;

	start = 0;
	newpos = pos;
	if (line == NULL)
	{
		exit(error_mess("LINE IS NULL IN PARSEINSTR\n"));
		return (-1);
	}
	if (newpos < ft_strlen(line))
	{
		while (line[newpos] && (line[newpos] == LABEL_CHAR
					|| line[newpos] == ' ' || line[newpos] == '\t'))
			newpos++;
		start = newpos;
		while (line[newpos] && line[newpos] != ' '
				&& line[newpos] != '\t' && line[newpos] != DIRECT_CHAR)
			newpos++;
	}
	ft_copycmd(line, start, newpos, new);
	if (ft_findcmd(new->cmd) == -1)
		exit(error_mess("ERROR THIS COMMAND DOES NOT EXIST"));
	return (newpos);
}
