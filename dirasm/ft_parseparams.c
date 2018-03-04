/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseparams.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:02:11 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/04 10:59:04 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_copypar(char *line, int start, int pos, t_par *par)
{
	int	i;

	par->par = (char *)malloc(sizeof(char) * (pos - start));
	i = 0;
	while (start < pos)
	{
		par->par[i] = line[start];
		start++;
		i++;
	}
	par->par[i] = '\0';
}

void	ft_parseparams(char *line, int pos, t_instr *new)
{
	int start;
	t_par *par;

	if (line)
	{
		if (pos < ft_strlen(line))
		{
			while (line[pos] && (line[pos] == ' ' || line[pos] == '\t'))
				pos++;
			while (line[pos] && line[pos] != '\n' && line[pos] != '#')
			{
				start = pos;
				while (line[pos] && (line[pos] == ' '|| line[pos] == '\t' || line[pos] == SEPARATOR_CHAR))
					pos++;
				while (line[pos] && line[pos] != ' ' && line[pos] != '\t' && line[pos] != SEPARATOR_CHAR)
				{
					if (line[pos] == '\n' || line[pos] == '#')
						break ;
					pos++;
				}
				if (line[start] == SEPARATOR_CHAR)
					start++;
				par = new_par("", &new->params);
				ft_copypar(line, start, pos, par);
			}
		}
	}
}
