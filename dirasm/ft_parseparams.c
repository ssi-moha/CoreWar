/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parseparams.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 10:02:11 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/11 15:59:17 by lfujimot         ###   ########.fr       */
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

static void ft_checkvalidchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isincharset(str[i], "0123456789") == -1)
			exit(error_mess("ERROR WRONG ARGS VALUE\n"));
		i++;
	}
}

static int	ft_checkpartype(t_par *par, int parindex, char *cmd)
{
	int i;
	int type;
	int n;

	type = 0;
	i = ft_findcmd(cmd);
	if (i >= 0)
	{
		if (par->type == 1)
		{
			ft_checkvalidchar(par->par + 1);
			n = ft_atoi(par->par + 1);
			if (n <= 0 || n > REG_NUMBER)
				exit(error_mess("ERROR REGISTER DOES NOT EXIST\n"));
			type = 1;
		}
		else if (par->type == 2 || par->type == 10)
			type = 2;
		else if (par->type == 4 || par->type == 12)
			type = 4;
		if (!((g_optab[i].typepar[parindex] & type) == type))
			return (-1);
	}
	return (1);
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
	while (line[pos] && line[pos] != '\n' && line[pos] != COMMENT_CHAR && line[pos] != ';')
	{
		par = 0;
		ft_skipbk(line, &pos, &s, &start);
		if (!(line[start] == ' ' || line[start] == '\t' || line[start]
			== COMMENT_CHAR || line[start] == '\n' || line[start] == ';') && line[start] != '\0')
		{
			par = new_par(NULL, &new->params);
			ft_copypar(line, start, pos, par);
			ft_addpar(par, &parindex, new);
		}
	}
	if (s >= parindex && s != 0)
		exit(error_mess("ERROR SYNTAX ERROR\n"));
}
