/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseparams.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:02:11 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/07 14:51:50 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_copypar(char *line, int start, int pos, t_par *par)
{
	int	i;
	if (par == 0)
		return ;
	par->par = (char *)malloc(sizeof(char) * (pos - start));
	if (par->par == 0)
		return ;
	i = 0;
	while (start < pos)
	{
		par->par[i] = line[start];
		start++;
		i++;
	}
	par->par[i] = '\0';
}

static int	ft_checkpartype(t_par *par, int parindex, char *cmd)
{
	int i;
	int type;

	type = 0;
	i = ft_findcmd(cmd);
	if (i >= 0)
	{
		if (par->type == 1)
			type = 1;
		else if (par->type == 2 || par->type == 10)
			type = 2;
		else if (par->type ==4 || par->type == 12)
			type = 4;
		if (!((g_optab[i].typepar[parindex] & type) == type))
			return (-1);
	}
	return (1);
}

void	ft_parseparams(char *line, int pos, t_instr *new)
{
	int start;
	t_par *par;
	int	parindex;

	if (line)
	{
		parindex = 0;	
		if (pos < ft_strlen(line))
		{
			while (line[pos] && (line[pos] == ' ' || line[pos] == '\t'))
				pos++;
			while (line[pos] && line[pos] != '\n' && line[pos] != '#')
			{
				start = pos;
				par = 0;
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
				if (!(line[start] == ' ' || line[start] == '\t'))
				{
					par = new_par(NULL, &new->params);
					ft_copypar(line, start, pos, par);
					par->type = ft_checkparams(par->par);
					if (par->type == -1)
						printf("ERREUR PARAMS\n");
					if (ft_checkpartype(par, parindex, new->cmd) == -1)
						printf("INCORECT PAR TYPE FOR THIS CMD\n");
					parindex++;
				}
			}
		}
	}
}
