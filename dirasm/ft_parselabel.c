/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parselabel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:13:15 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/08 10:43:39 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static int ft_findlabel(char *line)
{
	int i;

	i = 0;
	if (line)
	{
		while (line[i] && ft_isincharset(line[i], LABEL_CHARS) == 1)
		{
			i++;
		}
		if (i < ft_strlen(line))
			if (line[i] == LABEL_CHAR)
				return (i);
	}
	return (0);
}

static void	ft_copylabel(char *line, int size, t_instr *new, int start)
{
	int i;

	i = 0;
	if (new == 0)
		return ;
	new->label = (char *)malloc(sizeof(char) * size);
	if (new->label == 0)
		return ;
	while (i < size)
	{
		new->label[i] = line[start];
		i++;
		start++;
	}
	new->label[i] = '\0';
}

int		ft_parselabel(char *line, t_instr *new)
{
	int	sizelabel;
	int start;

	start = 0;
	while (line[start] && (line[start] == ' ' || line[start] == '\t'))
			start++;
	sizelabel = ft_findlabel(line + start);
	if (sizelabel > 0)
		ft_copylabel(line, sizelabel, new, start);
	return (sizelabel + start);
}
