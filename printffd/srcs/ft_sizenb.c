/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizenb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 19:05:00 by lfujimot          #+#    #+#             */
/*   Updated: 2017/12/16 15:18:57 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_sizenb(uintmax_t value, int base)
{
	int size;

	if (value == 0)
		return (1);
	size = 0;
	if (value == 0)
		return (1);
	while (value >= 1)
	{
		value = value / base;
		size++;
	}
	return (size);
}
