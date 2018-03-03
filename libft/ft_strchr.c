/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:48:10 by lfujimot          #+#    #+#             */
/*   Updated: 2018/02/15 12:48:15 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	const char	*s1;
	char		cc;
	size_t		size;

	s1 = s;
	cc = (char)c;
	size = ft_strlen(s);
	i = 0;
	while (s1[i] != cc && i < size)
		i++;
	if (s1[i] == cc)
		return (char *)(s1 + i);
	return (NULL);
}
