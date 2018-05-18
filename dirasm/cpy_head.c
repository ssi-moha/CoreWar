/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_head.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:39:43 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/05/18 11:54:38 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void		cpy_head(int ret, t_header *head, char **line, t_app *app)
{
	if (ret == 1)
	{
		ft_strncpy(head->prog_name, ft_strchr(*line, '"') + 1,
				ft_strclen(ft_strchr(*line, '"') + 1, '"'));
		app->checkcmd++;
		if (app->checkcmd > 1)
			exit(error_mess("ERROR NAME\n"));
	}
	else if (ret == 2)
	{
		ft_strncpy(head->comment, ft_strchr(*line, '"') + 1,
				ft_strclen(ft_strchr(*line, '"') + 1, '"'));
		app->checkcmdn++;
		if (app->checkcmdn > 1)
			exit(error_mess("ERROR COMMENT\n"));
	}
}
