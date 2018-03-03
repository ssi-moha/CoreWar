/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:43:20 by lfujimot          #+#    #+#             */
/*   Updated: 2018/02/15 12:43:22 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*s1;
	size_t					i;

	s1 = s;
	i = 0;
	while (i < n)
	{
		if (s1[i] == (unsigned char)c)
			return (void *)(s1 + i);
		i++;
	}
	return (NULL);
}
