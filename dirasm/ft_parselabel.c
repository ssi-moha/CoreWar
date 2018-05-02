/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parselabel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:13:15 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/02 15:47:48 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static int	ft_findlabel(char **line)
{
	size_t	i;

	i = 0;
	if (*line)
	{
		while (line[0][i] && ft_isincharset(line[0][i], LABEL_CHARS) == 1)
		{
			i++;
		}
		if (i < ft_strlen(*line))
			if (line[0][i] == LABEL_CHAR)
				return (i);
	}
	return (0);
}

static void	ft_copylabel(char **line, int size, t_instr **new, int start)
{
	int		i;
	char	*tmp;

	i = 0;
	if (*new == 0)
		return ;
	tmp = ft_strnew(size);
	if (tmp == 0)
		return ;
	while (i < size)
	{
		tmp[i] = line[0][start];
		i++;
		start++;
	}
	tmp[i] = '\0';
	new_label(tmp, &((*new)->label));
	free(tmp);
	tmp = 0;
}

int			ft_parselabel(char **line, t_instr **new)
{
	int	sizelabel;
	int start;

	start = 0;
	sizelabel = 0;
	while (line[0][start] && (line[0][start] == ' ' || line[0][start] == '\t'))
		start++;
	sizelabel = ft_findlabel(line + start);
	if (sizelabel > 0)
		ft_copylabel(line, sizelabel, new, start);
	return (sizelabel + start);
}
