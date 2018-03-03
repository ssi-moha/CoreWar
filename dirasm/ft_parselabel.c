/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parselabel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:13:15 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/03 19:15:41 by lfujimot         ###   ########.fr       */
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

static void	ft_copylabel(char *line, int size, t_instr *new)
{
	int i;

	i = 0;
	new->label = (char *)malloc(sizeof(char) * size);
	while (i < size)
	{
		new->label[i] = line[i];
		i++;
	}
	new->label[i] = '\0';
}

int		ft_parselabel(char *line, t_instr *new)
{
	int	sizelabel;
	
	sizelabel = ft_findlabel(line);
	if (sizelabel > 0)
		ft_copylabel(line, sizelabel, new);
	return (sizelabel);
}
