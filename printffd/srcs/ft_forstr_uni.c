/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forstr_uni.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:32:34 by lfujimot          #+#    #+#             */
/*   Updated: 2017/12/17 17:00:23 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_nbchar(wchar_t c)
{
	int nbchar;
	int bytes;

	bytes = 0;
	nbchar = 1;
	while (c)
	{
		c /= 2;
		bytes++;
	}
	if (bytes <= 7)
		nbchar = 1;
	else if (bytes <= 11)
		nbchar = 2;
	else if (bytes <= 16)
		nbchar = 3;
	else if (bytes <= 21)
		nbchar = 4;
	return (nbchar);
}

static void	ft_null(t_ctx *ctx, int prec)
{
	char	*n;
	int		i;

	n = "(null)";
	i = 0;
	while ((i < prec || prec == -1) && n[i])
		ft_flush(ctx, n[i++]);
}

static int	ft_strlen_uni(wchar_t *str, int prec)
{
	int i;
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
		i = 0;
		if (prec > 0)
			while (str[i] && ft_nbchar(str[i]) <= prec - size)
				size += ft_nbchar(str[i++]);
		else if (prec == -1)
			while (str[i])
				size += ft_nbchar(str[i++]);
		return (size);
	}
}

static void	ft_addchartobuffer(t_ctx *ctx, t_arg *current, wchar_t *str)
{
	int i;
	int j;

	if (str == NULL)
		ft_null(ctx, current->prec);
	else
	{
		i = 0;
		j = 0;
		while (str[i] && (j + ft_nbchar(str[i]) <= current->prec ||
					current->prec == -1))
		{
			ft_forchar_uni(str[i], current, ctx);
			j += ft_nbchar(str[i++]);
		}
	}
}

void		ft_forstr_uni(wchar_t *str, t_arg *current, t_ctx *ctx)
{
	int		i;
	int		size;
	char	w;
	int		width;

	width = current->width;
	current->width = -1;
	w = (current->flags.zero) ? '0' : ' ';
	size = ft_strlen_uni(str, current->prec);
	i = 0;
	if (!current->flags.moins)
		while (i++ < width - size)
			ft_flush(ctx, w);
	ft_addchartobuffer(ctx, current, str);
	i = 0;
	if (current->flags.moins)
		while (i++ < width - size)
			ft_flush(ctx, ' ');
}
