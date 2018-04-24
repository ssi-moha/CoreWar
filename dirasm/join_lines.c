/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:36:50 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/04/24 14:39:10 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

char	*join_lines(int fd, char *line)
{
	char *str;
	char *ret;

	get_next_line(fd, &str);
	ret = ft_strjoin(line, "\n");
	return (ft_strjoin(ret, str));
}
