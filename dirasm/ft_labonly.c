/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_labonly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:26:20 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/02 15:41:34 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_addlabel(char **line, int size, int start, t_app **app)
{
	int		i;
	char	*tmp;

	i = 0;
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
	new_label(tmp, &(*app)->tmplab);
	free(tmp);
	tmp = 0;
}

int			ft_labonly(t_app **app, char **line)
{
	int		i;
	int		j;
	int		lab;
	int		x;

	lab = 0;
	i = 0;
	while (line[0][i] && (line[0][i] == ' ' || line[0][i] == '\t'))
		i++;
	j = i;
	while (line[0][j] && (ft_isincharset(line[0][j], LABEL_CHARS) == 1))
		j++;
	if (line[0][j] == LABEL_CHAR)
	{
		lab = 1;
		x = (j + 1);
		while (line[0][x] && (line[0][x] == ' ' || line[0][x] == '\t'))
			x++;
		if (line[0][x] == '\0')
		{
			ft_addlabel(line, (j + 1) - i - 1, i, app);
			return (1);
		}
	}
	return (0);
}
