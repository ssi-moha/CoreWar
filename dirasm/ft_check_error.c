/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 09:29:05 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/18 09:30:05 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void			ft_check_error(int ret, char *line)
{
	if (ret == 1)
	{
		if (ft_strlen(line) > PROG_NAME_LENGTH)
			exit(error_mess("ERROR NAME TOO LONG\n"));
	}
	else if (ret == 2)
	{
		if (ft_strlen(line) > COMMENT_LENGTH)
			exit(error_mess("ERROR COMMENT TOO LONG\n"));
	}
}
