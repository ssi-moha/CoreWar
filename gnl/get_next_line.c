/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:34:01 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/03 17:28:49 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "../libft/libft.h"

static char			*ft_custom_strjoin(char *s1, char const *s2)
{
	char	*tmp;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tmp = ft_strnew(len1 + len2 + 1);
	if (tmp == NULL)
		return (NULL);
	tmp[len1 + len2 + 1] = '\0';
	len1 = 0;
	while (s1[len1])
	{
		tmp[len1] = s1[len1];
		len1++;
	}
	len2 = 0;
	while (s2[len2])
		tmp[len1++] = s2[len2++];
	free(s1);
	s1 = NULL;
	return (tmp);
}

static t_file		*get_file(t_file **file, const int fd)
{
	t_file			*tmp;
	t_file			*new;

	tmp = *file;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if ((new = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	new->fd = fd;
	new->b = ft_strnew(1);
	new->next = *file;
	*file = new;
	return (new);
}

static char			*get_line(t_file *file)
{
	int		i;
	char	*tmp;
	char	*str;

	str = file->b;
	i = 0;
	while (file->b[i] && file->b[i] != '\n')
		i++;
	tmp = ft_strsub(file->b, 0, i);
	file->b = ft_strsub(str, i + 1, ft_strlen(file->b));
	free(str);
	str = NULL;
	return (tmp);
}

static int			ft_remove_fd(t_file *cur, t_file **lst, char **line)
{
	t_file *tmp;
	t_file *tmp2;

	tmp = *lst;
	tmp2 = tmp->next;
	ft_strclr(*line);
	if (cur == *lst)
	{
		*lst = cur->next;
		free(cur->b);
		free(cur);
	}
	else
		while (tmp2)
		{
			if (tmp2 == cur)
			{
				tmp->next = tmp2->next;
				free(tmp2->b);
				free(tmp2);
			}
			tmp = tmp2;
			tmp2 = tmp2->next;
		}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_file	*file;
	t_file			*current;
	char			buf[BUFF_S + 1];
	int				res;

	if (fd < 0 || ((current = (get_file(&file, fd))) == NULL))
		return (-1);
	while (ft_strchr(current->b, '\n') == NULL)
	{
		res = read(fd, buf, BUFF_S);
		if (res < 0)
			return (-1);
		buf[res] = '\0';
		current->b = ft_custom_strjoin(current->b, buf);
		if (res == 0 && current->b[0] == '\0')
			return (ft_remove_fd(current, &file, line));
		else if (res == 0)
			break ;
	}
	*line = get_line(current);
	return (1);
}
