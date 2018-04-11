/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_com_and_blank.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:16:29 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/11 15:57:52 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int	ft_skip_com_and_blank(char *line)
{
	int i;

	i = 0;
	if (line)
	{
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line[i] == '\0' || line[i] == COMMENT_CHAR || line[i] == ';')
			return (1);
	}
	return (0);
}
