/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:38:07 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/05 15:50:54 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		check_name_cmt(char *str)
{
	int i;

	i = 0;
	if (str && !ft_strncmp(str, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		while (str[i])
		{
			if (!ft_isprint(str[i]) && str[i] != ' ' && str[i] != '\t')
				return (0);
			i++;
		}
		if (i > PROG_NAME_LENGTH)
			exit (error_mess("PROG_NAME IS TOO LARGE"));
		return (1);
	}
	if (str && !ft_strncmp(str, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
	{
		while (str[i])
		{
			if (!ft_isprint(str[i]) && str[i] != ' ' && str[i] != '\t')
				return (0);
			i++;
		}
		if (i > COMMENT_LENGTH)
			exit(error_mess("COMMENT IS TOO LARGE"));
		return (2);
	}
	return (0);
}
/*
int		check_format(char *str)
{
	int i;
	int count;

	i = 0;
	if (skip_blank(str))
		return (-1);
	if (check_name_cmt(str))
		return (1);
	while (str[i])
		i++;
	return (1);
}*/
