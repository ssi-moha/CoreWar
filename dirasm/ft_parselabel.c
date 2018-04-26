/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parselabel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 18:13:15 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/26 12:52:34 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static int	ft_findlabel(char *line)
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
	int		i;
	char	*tmp;

	i = 0;
	if (new == 0)
		return ;
	tmp = (char *)malloc(sizeof(char) * size);
	if (tmp == 0)
		return ;
	while (i < size)
	{
		tmp[i] = line[start];
		i++;
		start++;
	}
	tmp[i] = '\0';
	new_label(tmp, &(new->label));
	printf("%s %s\n", tmp, new->label->l);
	free(tmp);
}

int			ft_parselabel(char *line, t_instr *new)
{
	int	sizelabel;
	int start;

	start = 0;
	sizelabel = 0;
	while (line[start] && (line[start] == ' ' || line[start] == '\t'))
		start++;
	sizelabel = ft_findlabel(line + start);
	if (sizelabel > 0)
	{
		printf("line\n");
		ft_copylabel(line, sizelabel, new, start);
	}
	if (new->label)
		printf("ICI %s\n", new->label->l);
	else
		printf("PASLAB %s\n", new->cmd);
	return (sizelabel + start);
}
