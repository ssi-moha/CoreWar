/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:52:44 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/02 18:09:29 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	dst = ft_strnew(len);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (i + start < len)
		{
			dst[i] = s[i + start];
		}
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
