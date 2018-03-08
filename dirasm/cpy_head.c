/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_head.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:39:43 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/08 13:53:12 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		cpy_head(int ret, t_header *head, char **line)
{
	if (ret == 1)
		ft_strncpy(head->prog_name, ft_strchr(*line, '"') + 1,
				ft_strclen(ft_strchr(*line, '"') + 1, '"'));
	else if (ret == 2)
		ft_strncpy(head->comment, ft_strchr(*line, '"') + 1,
				ft_strclen(ft_strchr(*line, '"') + 1, '"'));
	ft_strdel(line);
	return (1);
}
