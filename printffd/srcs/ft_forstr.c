/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:16:55 by lfujimot          #+#    #+#             */
/*   Updated: 2017/12/16 12:34:58 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_null(t_ctx *ctx, int prec)
{
	char	*n;
	int		i;

	n = "(null)";
	i = 0;
	while ((i < prec || prec == -1) && n[i])
		ft_flush(ctx, n[i++]);
}

static int	ft_strlenprec(char *str, int prec)
{
	int size;

	if (str == NULL)
	{
		if (prec == -1)
			return (6);
		else
			return (prec);
	}
	else
	{
		size = 0;
		if (prec > 0)
			while (str[size] && size < prec)
				size++;
		else if (prec == -1)
			while (str[size])
				size++;
		return (size);
	}
}

static void	ft_addchartobuffer(t_ctx *ctx, t_arg *current, char *str)
{
	int i;

	if (str == NULL)
		ft_null(ctx, current->prec);
	else
	{
		i = 0;
		while (str[i] && (i < current->prec || current->prec == -1))
			ft_forchar(str[i++], current, ctx);
	}
}

void		ft_forstr(char *str, t_arg *current, t_ctx *ctx)
{
	int		i;
	int		size;
	char	zero;
	int		width;

	width = current->width;
	current->width = -1;
	if (current->flags.zero)
		zero = '0';
	else
		zero = ' ';
	size = ft_strlenprec(str, current->prec);
	i = 0;
	if (current->flags.moins == 0)
		while (i++ < width - size)
			ft_flush(ctx, zero);
	ft_addchartobuffer(ctx, current, str);
	i = 0;
	if (current->flags.moins)
		while (i++ < width - size)
			ft_flush(ctx, ' ');
}
