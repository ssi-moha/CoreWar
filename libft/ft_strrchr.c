/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:52:55 by lfujimot          #+#    #+#             */
/*   Updated: 2018/02/15 12:52:56 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s1;
	size_t		len;
	char		cc;

	s1 = s;
	cc = c;
	len = ft_strlen(s);
	while (s1[len] != cc && len != 0)
		len--;
	if (s1[len] == cc)
		return (char *)(s1 + len);
	return (NULL);
}
