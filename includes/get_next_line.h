/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:33:42 by lfujimot          #+#    #+#             */
/*   Updated: 2018/02/15 16:04:21 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_S 1
# include "../libft/libft.h"

typedef	struct		s_file
{
	int				fd;
	char			*b;
	struct s_file	*next;
}					t_file;

int					get_next_line(const int fd, char **line);
#endif
