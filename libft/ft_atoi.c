/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:34:59 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/21 18:31:53 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_in_charset(char c)
{
	if (c == ' ' || c == '\t'
			|| c == '\n' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

intmax_t		ft_atoi(const char *str)
{
	intmax_t	result;
	int			is_neg;
	int			count;

	is_neg = 1;
	result = 0;
	while (ft_in_charset(*str) == 1)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_neg = -1;
		str++;
	}
	count = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
		if (++count > 19)
			return ((is_neg == -1) ? 0 : -1);
	}
	return (result * is_neg);
}
