/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 10:43:31 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/10 17:38:21 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_flush(t_ctx *ctx, char c)
{
	if (ctx->pos == BUFF_SIZE - 1)
	{
		write(ctx->fd, ctx->buf, ctx->pos);
		ctx->pos = 0;
	}
	ctx->size++;
	ctx->buf[ctx->pos++] = c;
}
