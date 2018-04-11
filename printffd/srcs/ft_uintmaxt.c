/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmaxt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 17:16:15 by lfujimot          #+#    #+#             */
/*   Updated: 2017/12/15 15:09:25 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_uintmaxt(uintmax_t nb, t_arg *current, t_ctx *ctx)
{
	char sign[2];

	sign[0] = 0;
	ft_fornb(nb, current, ctx, sign);
}
