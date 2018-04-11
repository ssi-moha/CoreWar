/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 14:45:53 by lfujimot          #+#    #+#             */
/*   Updated: 2017/12/15 16:27:46 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_intmaxt(intmax_t nb, t_arg *current, t_ctx *ctx)
{
	intmax_t	n;
	char		sign[2];

	if (nb < 0)
	{
		sign[0] = '-';
		n = -nb;
	}
	else
	{
		sign[0] = 0;
		n = nb;
	}
	ft_fornb(n, current, ctx, sign);
}
