/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:52:34 by lfujimot          #+#    #+#             */
/*   Updated: 2018/02/15 12:52:35 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	size_t	end;
	size_t	len;
	int		i;
	char	*new;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (s[i] && (s[i] == '\t' || s[i] == '\n' || s[i] == ' '))
		i++;
	start = i;
	i = len - 1;
	while (i >= 0 && (s[i] == '\t' || s[i] == '\n' || s[i] == ' '))
		i--;
	end = i + 1;
	if (end == 0)
		return (ft_strnew(1));
	new = ft_strnew(end - start);
	if (new == NULL)
		return (NULL);
	new = ft_strsub(s, start, end - start);
	return (new == NULL ? NULL : new);
}
