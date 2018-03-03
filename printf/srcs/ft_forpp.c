/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forpp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 14:11:01 by lfujimot          #+#    #+#             */
/*   Updated: 2017/12/16 19:46:24 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_forpp(uintptr_t p, t_arg *current, t_ctx *ctx)
{
	t_arg cur;

	cur.type = 'x';
	cur.width = current->width;
	cur.prec = current->prec;
	cur.mod = current->mod;
	cur.flags = current->flags;
	cur.flags.hash = 1;
	if (p == 0)
	{
		cur.mod = UNDEF;
		if (cur.flags.moins)
			cur.flags.zero = -1;
	}
	ft_uintmaxt(p, &cur, ctx);
}
