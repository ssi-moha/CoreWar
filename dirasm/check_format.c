/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 14:38:07 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/05 09:59:36 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		check_name_cmt(char *str)
{
	int i;

	i = 0;
	if (!ft_strncmp(str, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
	{
		while (str[i])
		{
			if (!ft_isprint(str[i]))
				return (0);
		}
		return (1);
	}
	if (!ft_strncmp(str, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
	{
		while (str[i])
		{
			if (!ft_isprint(str[i]))
				return (0);
		}
		return (1);
	}
	return (0);
}

int		check_format(char *str)
{
	int i;
	int count;

	i = 0;
	if (check_name_cmt(str))
		return (1);
	while (str[i])
		i++;
	return (1);
}
