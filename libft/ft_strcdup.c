/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:01:49 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/05/02 19:09:38 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strcdup(const char *src, int c)
{
	char	*dest;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (src == 0)
		return (0);
	dest = ft_strnew(ft_strlen(src));
	if (dest == 0)
		return (0);
	while (src[i] && src[i] != c)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
