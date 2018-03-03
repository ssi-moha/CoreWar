/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:53:21 by lfujimot          #+#    #+#             */
/*   Updated: 2018/02/15 12:53:22 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			len1;
	size_t			i;
	char			*src;

	len1 = ft_strlen(needle);
	if (len1 == 0)
		return ((char *)(haystack));
	i = 0;
	src = ft_strsub(haystack, 0, len);
	while (src[i] && i < len)
	{
		if (src[i] == needle[0])
		{
			if (ft_strncmp((src + i), needle, len1) == 0)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}
