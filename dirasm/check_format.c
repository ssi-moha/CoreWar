/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:38:07 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/08 10:50:21 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		check_name_cmt(char *str)
{
	int i;

	i = 0;
	while (*str == ' ' || *str == '\t')
		str++;
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
	else if (str && !ft_strncmp(str, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
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
	else if (str[0] == '.')
		exit(error_mess("Invalid .command"));
	return (0);
}
