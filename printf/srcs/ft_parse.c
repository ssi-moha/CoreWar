/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:00:53 by lfujimot          #+#    #+#             */
/*   Updated: 2017/12/17 17:01:24 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_parse_mod(t_arg *current, const char *format, int i)
{
	if (format[i] == 'h' && format[i + 1] == 'h' && HH > current->mod)
	{
		current->mod = HH;
		i++;
	}
	else if (format[i] == 'h' && format[i + 1] != 'h' && H > current->mod)
		current->mod = H;
	else if (format[i] == 'l' && format[i + 1] != 'l' && L > current->mod)
		current->mod = L;
	else if (format[i] == 'l' && format[i + 1] == 'l' && LL > current->mod)
	{
		current->mod = LL;
		i++;
	}
	else if (format[i] == 'z' && Z > current->mod)
		current->mod = Z;
	else if (format[i] == 'j')
		current->mod = J;
	return (i + 1);
}

static int	ft_parse_flag(t_arg *current, const char *format, int i)
{
	while (ft_isflag(format[i]))
	{
		if (format[i] == '-')
			current->flags.moins = 1;
		if (format[i] == '+')
			current->flags.plus = 1;
		if (format[i] == '0')
			current->flags.zero = 1;
		if (format[i] == ' ')
			current->flags.space = 1;
		if (format[i] == '#')
			current->flags.hash = 1;
		i++;
	}
	return (i);
}

static int	ft_parse_notvalidchar(t_arg *current, t_ctx *ctx, int i, int *pour)
{
	int j;
	int zero;

	if (current->flags.zero)
		zero = '0';
	else
		zero = ' ';
	j = 2;
	while (j++ <= current->width && current->width > 0 &&
			current->flags.moins == 0)
		ft_flush(ctx, zero);
	ft_flush(ctx, ctx->format[i++]);
	*pour = 1;
	j = 2;
	while (j++ <= current->width && current->width > 0 &&
			current->flags.moins == 1)
		ft_flush(ctx, ' ');
	return (i);
}

static int	ft_parse_prec_width(int i, t_arg *current, t_ctx *ctx)
{
	if (ctx->format[i] == '.')
	{
		current->prec = ft_atoi_sp(ctx->format, ++i);
		while (ft_isdigit(ctx->format[i]) == 1 && ctx->format[i])
			i++;
	}
	else
	{
		current->width = ft_atoi_sp(ctx->format, i);
		while (ft_isdigit(ctx->format[i]) == 1 &&
				ctx->format[i] != '.' && ctx->format[i])
			i++;
	}
	return (i);
}

void		ft_parse(t_arg *current, int i, t_ctx *ctx)
{
	int f;
	int pour;

	pour = 0;
	f = 0;
	i++;
	while (ft_istype(ctx->format[i]) != 1 && ctx->format[i] && pour == 0)
		if (ft_isflag(ctx->format[i]) == 1)
			i = ft_parse_flag(current, ctx->format, i);
		else if (ft_ismod(ctx->format[i]) == 1)
			i = ft_parse_mod(current, ctx->format, i);
		else if (ctx->format[i] == '.')
			i = ft_parse_prec_width(i, current, ctx);
		else if (ft_isdigit(ctx->format[i]) == 1)
			i = ft_parse_prec_width(i, current, ctx);
		else if (!(ft_istype(ctx->format[i]) || ft_ismod(ctx->format[i])
					|| ft_isflag(ctx->format[i]) ||
					ft_isdigit(ctx->format[i])))
			i = ft_parse_notvalidchar(current, ctx, i, &pour);
		else if (ctx->format[i])
			i++;
	if (ft_istype(ctx->format[i]) && pour == 0)
		current->type = ctx->format[i];
	current->endpos = i;
}
