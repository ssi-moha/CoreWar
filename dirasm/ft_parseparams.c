/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseparams.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:02:11 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/02 15:46:35 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void	ft_copypar(char *line, int start, int pos, t_par *par)
{
	int	i;

	if (par == 0)
		return ;
	par->par = ft_strnew(pos - start);
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

static int	ft_incpos(char *line, int pos)
{
	while (line[pos] && line[pos] != ' ' && line[pos] != '\t' && line[pos] !=
			SEPARATOR_CHAR)
	{
		if (line[pos] == '\n' || line[pos] == COMMENT_CHAR || line[pos] == ';')
			break ;
		pos++;
	}
	return (pos);
}

static void	ft_skipbk(char *line, int *pos, int *s, int *start)
{
	while (line[*pos] && (line[*pos] == ' ' || line[*pos] == '\t' || line[*pos]
				== SEPARATOR_CHAR))
	{
		if (line[*pos] == SEPARATOR_CHAR)
			*s = *s + 1;
		*pos = *pos + 1;
	}
	*start = *pos;
	*pos = ft_incpos(line, *pos);
	if (line[*start] == SEPARATOR_CHAR)
	{
		*s = *s + 1;
		*start = *start + 1;
	}
}

static void	ft_addpar(t_par *par, int *parindex, t_instr *new)
{
	par->type = ft_checkparams(par->par);
	if (par->type == -1)
		exit(error_mess("ERREUR PARAMS\n"));
	if (ft_checkpartype(par, *parindex, new->cmd) == -1)
		exit(error_mess("INCORECT PAR TYPE FOR THIS CMD\n"));
	*parindex = *parindex + 1;
}

void		ft_parseparams(char *line, int pos, t_instr *new)
{
	int		start;
	t_par	*par;
	int		parindex;
	int		s;

	s = 0;
	parindex = 0;
	while (line[pos] && (line[pos] == ' ' || line[pos] == '\t'))
		pos++;
	while (line[pos] && line[pos] != '\n' && line[pos] !=
			COMMENT_CHAR && line[pos] != ';')
	{
		par = 0;
		ft_skipbk(line, &pos, &s, &start);
		if (!(line[start] == ' ' || line[start] == '\t' || line[start]
			== COMMENT_CHAR || line[start] == '\n' || line[start] == ';')
				&& line[start] != '\0')
		{
			par = new_par(NULL, &new->params);
			ft_copypar(line, start, pos, par);
			ft_addpar(par, &parindex, new);
		}
	}
	if (s >= parindex && s != 0)
		exit(error_mess("ERROR SYNTAX ERROR\n"));
}
