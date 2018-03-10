/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadinram.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:29:42 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/10 11:40:39 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void	ft_loadinram(unsigned char *data, int i, int nbplayers, t_vm *vm)
{
	int start;

	start = (MEM_SIZE / nbplayers) * (i - 1);
	printf("%d\n", start);
}
