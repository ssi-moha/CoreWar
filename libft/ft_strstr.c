/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:54:27 by lfujimot          #+#    #+#             */
/*   Updated: 2018/02/15 12:54:29 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		len;
	int			i;
	const char	*src;

	src = haystack;
	len = ft_strlen(needle);
	if (len == 0)
		return ((char *)src);
	i = 0;
	while (src[i])
	{
		if (src[i] == needle[0])
		{
			if (ft_strncmp((src + i), needle, len) == 0)
				return ((char *)(src + i));
		}
		i++;
	}
	return (NULL);
}
