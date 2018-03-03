/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_sp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:24:08 by lfujimot          #+#    #+#             */
/*   Updated: 2017/12/17 16:23:19 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	ft_getnb(int n, char type)
{
	char *nbbase;

	if (type == 'X')
		nbbase = "0123456789ABCDEF";
	else
		nbbase = "0123456789abcdef";
	return (nbbase[n]);
}

static void	ft_nb_prec(t_arg *current, int size, t_ctx *ctx)
{
	int		i;

	if ((current->type == 'o' || current->type == 'O') && current->flags.hash)
		size++;
	if (size < current->prec)
	{
		i = 0;
		while (i < current->prec - size)
		{
			ft_flush(ctx, '0');
			i++;
		}
	}
}

void		ft_itoa_base_sp(t_nb *n, char type, t_ctx *ctx, t_arg *current)
{
	int		size;
	int		i;
	char	nb[128];

	size = ft_sizenb(n->val, n->base);
	ft_nb_prec(current, size, ctx);
	i = size - 1;
	while (i >= 0)
	{
		nb[i] = ft_getnb(n->val % n->base, type);
		n->val /= n->base;
		i--;
	}
	i = 0;
	while (i < size)
		ft_flush(ctx, nb[i++]);
}
