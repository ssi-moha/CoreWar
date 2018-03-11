/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 17:54:00 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/11 18:31:39 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void	ft_setint(int *tab, int value, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
		tab[i++] = value;
}
