/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseinstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:11:04 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/05 14:21:40 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void		ft_copycmd(char *line, int start, int newpos, t_instr *instr)
{
	int	i;

	if (instr == 0)
		return ;
	instr->cmd = (char *)malloc(sizeof(char) * (newpos - start));
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
}

int				ft_parseinstr(char *line, int pos, t_instr *new)
{
	int newpos;
	int start;

	newpos = pos;
	if (line == NULL)
	{
		printf("LINE IS NULL IN PARSEINSTR\n");
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
		printf("ERROR THIS COMMAND DOES NOT EXIST\n");
	return (newpos);
}
