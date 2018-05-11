/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:10:10 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/11 11:12:01 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strendup(const char *src, int c)
{
	char	*dest;
	int		i;
	int		len;

	len = ft_strlen(src);
	i = 0;
if (src == 0)
	return (0);
while (len > 0 && src[len] != c)
	len--;
	dest = ft_strnew(len);
if (dest == 0)
	return (0);
while (src[i] && i < len)
{
	dest[i] = src[i];
	i++;
}
dest[i] = '\0';
return (dest);
}
