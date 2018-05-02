/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:38:07 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/05/02 14:51:24 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static int		ft_check_comment(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (i > COMMENT_LENGTH)
		exit(error_mess("COMMENT IS TOO LARGE"));
	return (2);
}

static int		ft_check_name(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (i > PROG_NAME_LENGTH)
		exit(error_mess("PROG_NAME IS TOO LARGE"));
	return (1);
}

int				check_name_cmt(char **str)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while ((*str)[j] == ' ' || (*str)[j] == '\t')
		j++;
	if ((*str)[j] && !ft_strncmp(*str + j, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		return (ft_check_name(*str + j));
	else if ((*str)[j] &&
			!ft_strncmp(*str + j, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		return (ft_check_comment(*str + j));
	else if ((*str)[j] == '.')
		exit(error_mess("Invalid .command"));
	return (0);
}
