/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:45:53 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/09 18:53:32 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void		ft_custom_concat(char *data, char *buf, int start, int end)
{
	int		i;
	int		j;

	j = 0;
	i = start;
	while (i < end + start)
	{
		data[i] = buf[j];
		i++;
		j++;
	}
}

char			*ft_openfile(char *file)
{
	char	*data;
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		r;
	int		size;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(error_mess("File can't be open\n"));
	data = ft_strnew(0);
	size = 0;
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUF_SIZE);
		buf[BUF_SIZE] = '\0';
		size += r;
		data = realloc(data, size);
		ft_custom_concat(data, buf, size - r, r);
	}
	close(fd);
	return (data);
}
