/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 12:02:15 by lfujimot          #+#    #+#             */
/*   Updated: 2017/12/17 17:08:15 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_init_ctx(t_ctx *ctx, const char *format)
{
	ctx->format = format;
	ctx->pos = 0;
	ctx->size = 0;
}

static void	ft_init_arg(t_arg *current)
{
	current->type = 0;
	current->flags.moins = 0;
	current->flags.plus = 0;
	current->flags.zero = 0;
	current->flags.space = 0;
	current->flags.hash = 0;
	current->width = 0;
	current->prec = -1;
	current->mod = NONE;
	current->endpos = 0;
}

static int	ft_do_printf(va_list va, t_ctx *ctx)
{
	t_arg	current;
	int		i;
	int		err;

	i = 0;
	while (ctx->format[i])
	{
		if (ctx->format[i] == '%')
		{
			ft_init_arg(&current);
			ft_parse(&current, i, ctx);
			err = ft_manage_type(&current, va, ctx);
			if (err == -1)
				return (err);
			if (ft_istype(current.type) == 0 && !ctx->format[i])
				break ;
			else if (ft_istype(current.type) == 0)
				current.endpos--;
			i = current.endpos + 1;
		}
		else
			ft_flush(ctx, ctx->format[i++]);
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list va;
	t_ctx	ctx;
	int		err;

	ft_init_ctx(&ctx, format);
	va_start(va, format);
	err = ft_do_printf(va, &ctx);
	if (err == -1)
		return (-1);
	ctx.buf[ctx.pos] = '\0';
	write(1, ctx.buf, ctx.pos);
	va_end(va);
	return (ctx.size);
}
