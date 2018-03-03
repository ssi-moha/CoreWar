/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forchar_uni.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:26:16 by lfujimot          #+#    #+#             */
/*   Updated: 2017/12/17 16:09:28 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_printf.h"

static int	ft_mod(int nbchar)
{
	if (nbchar == 4)
		return (8);
	else if (nbchar == 3)
		return (16);
	else if (nbchar == 2)
		return (32);
	else if (nbchar == 1)
		return (128);
	return (0);
}

static int	ft_un(int nbchar)
{
	if (nbchar == 4)
		return (240);
	else if (nbchar == 3)
		return (224);
	else if (nbchar == 2)
		return (192);
	else if (nbchar == 1)
		return (0);
	return (0);
}

static int	ft_nbchar(wchar_t tmp)
{
	int	bytes;
	int	nbchar;

	bytes = 0;
	nbchar = 1;
	while (tmp)
	{
		tmp /= 2;
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

static void	ft_space(int nbchar, t_arg *current, t_ctx *ctx, int before)
{
	int		i;
	char	w;

	w = (current->flags.zero) ? '0' : ' ';
	i = nbchar;
	if (before)
	{
		if (current->flags.moins == 0)
			while (i++ < current->width)
				ft_flush(ctx, w);
	}
	else
	{
		if (current->flags.moins)
			while (i++ < current->width)
				ft_flush(ctx, ' ');
	}
}

int			ft_forchar_uni(wchar_t c, t_arg *current, t_ctx *ctx)
{
	unsigned char	uni[4];
	int				nbchar;
	int				i;
	char			w;

	if (c > 2097151 || c < 0)
		return (-1);
	w = (current->flags.zero) ? '0' : ' ';
	nbchar = ft_nbchar(c);
	ft_space(nbchar, current, ctx, 1);
	i = nbchar - 1;
	while (i > 0)
	{
		uni[i--] = 128 + c % 64;
		c /= 64;
	}
	uni[0] = ft_un(nbchar) + c % ft_mod(nbchar);
	i = 0;
	while (i < nbchar)
		ft_flush(ctx, uni[i++]);
	ft_space(nbchar, current, ctx, 0);
	return (0);
}
