/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 13:45:53 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/09 14:18:38 by lfujimot         ###   ########.fr       */
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
		printf("ggg\n");	
		r = read(fd, buf, BUF_SIZE);
		buf[BUF_SIZE] = '\0';
		size += r;
		printf("BUF %s %d\n", buf, r);
		data = realloc(data, size);
		ft_strcat(data, buf);
		printf("DATA %s %d\n", data, r);
	}
	printf("%s\n", data);
	return (data);
}
