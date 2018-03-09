/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:45:53 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/09 16:40:25 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

char	*ft_openfile(char *file)
{
	char	*data;
	int		fd;
	char 	buf[BUF_SIZE + 1];
	int		r;
	int		size;

	fd = open(file, O_RDONLY);
	data = ft_strnew(0);
	size = 0;
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUF_SIZE);
		buf[BUF_SIZE] = '\0';
		size += r;
		//write(1, buf, r);
		printf("sssssssssssssssssssss\n");
		data = realloc(data, size);
		ft_strncat(data, buf, size);
	}
	write(1, data, size);
	return (data);
}
