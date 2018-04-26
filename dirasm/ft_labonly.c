/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_labonly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:26:20 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/26 17:33:33 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_addlabel(char *line, int size, int start, t_app *app)
{
	int		i;
	char	*tmp;

	i = 0;
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
	new_label(tmp, &(app->tmplab));
	free(tmp);
}

int			ft_labonly(t_app *app, char *line)
{
	int		i;
	int		j;
	int		lab;
	int		x;

	lab = 0;
	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	j = i;
	while (line[j] && (ft_isincharset(line[j], LABEL_CHARS) == 1))
		j++;
	if (line[j] == LABEL_CHAR)
	{
		lab = 1;
		x = (j + 1);
		while (line[x] && (line[x] == ' ' || line[x] == '\t'))
			x++;
		if (line[x] == '\0')
		{
			ft_addlabel(line, (j + 1) - i - 1, i, app);
			return (1);
		}
	}
	return (0);
}
