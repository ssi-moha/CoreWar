/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:45:53 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/03 09:00:38 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

static void		ft_custom_concat(unsigned char *data, unsigned char *buf,
									int start, int end)
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

static void		ft_checksize(unsigned int size, unsigned char *data, int fd)
{
	unsigned int sizeh;

	sizeh = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4;
	if (size < sizeh)
	{
		free(data);
		close(fd);
		exit(error_mess("ERROR CHAMP TOO SMALL FOR THE VM\n"));
	}
	else if (size != (ft_checkprogsize(data) + sizeh))
	{
		free(data);
		close(fd);
		exit(error_mess("CHAMP SIZE NOT EQUAL TO THE SIZE IN THE HEADER\n"));
	}
}

unsigned char	*ft_openfile(char *file)
{
	unsigned char	*data;
	int				fd;
	unsigned char	buf[BUF_SIZE + 1];
	int				r;
	unsigned int	size;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(error_mess("File error\n"));
	data = (unsigned char*)ft_strnew(0);
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
	ft_checksize(size, data, fd);
	close(fd);
	return (data);
}
