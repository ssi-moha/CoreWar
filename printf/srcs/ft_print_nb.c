/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 19:23:36 by lfujimot          #+#    #+#             */
/*   Updated: 2017/12/17 17:28:53 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_sign(char sign[2], t_arg *cur, int *s, uintmax_t nb)
{
	if ((cur->type == 'd' || cur->type == 'i' || cur->type == 'D') &&
			sign[0] != '-')
	{
		if (cur->flags.plus)
			sign[0] = '+';
		else if (cur->flags.space)
			sign[0] = ' ';
	}
	else if (cur->flags.hash)
	{
		if ((cur->type == 'o' || cur->type == 'O') &&
				(nb != 0 || cur->prec != -1))
			sign[0] = '0';
		else if (nb != 0 || cur->mod == UNDEF)
		{
			if (cur->type == 'x' || cur->type == 'X')
			{
				sign[0] = '0';
				sign[++*s] = (cur->type == 'x') ? 'x' : 'X';
			}
		}
	}
	return (sign);
}

static void	ft_add(t_nb *n, t_arg *cur, t_ctx *ctx)
{
	if (!(n->val == 0 && (cur->type == 'd' || cur->type == 'D' ||
					cur->type == 'i' || cur->type == 'u' || cur->type == 'U' ||
					cur->type == 'x' || cur->type == 'X') && cur->prec == 0) &&
			!((cur->type == 'o' || cur->type == 'O') && cur->prec == 0 &&
				n->val == 0 && cur->flags.hash == 0))
		ft_itoa_base_sp(n, cur->type, ctx, cur);
}

static void	ft_addtobuf(t_arg *cur, t_ctx *ctx, t_nb *n, int scp[3])
{
	int i;

	if (n->val == 0 && cur->flags.zero == 0 && (!cur->flags.hash ||
				cur->mod == UNDEF) && cur->prec != 0)
		cur->width--;
	i = 0;
	if (cur->flags.moins == 0)
		while (i++ < cur->width - scp[0])
			ft_flush(ctx, scp[1]);
	if (scp[1] != '0' && n->sign[0] != 0 && scp[2] == 0)
	{
		if (n->val != 0 || cur->prec > 1 || cur->prec == -1 || cur->type == 'd'
				|| cur->type == 'D' || cur->type == 'i' || cur->type == 'u' ||
				cur->type == 'U' || cur->mod == UNDEF)
			ft_flush(ctx, n->sign[0]);
		if (cur->flags.hash && (cur->type == 'x' ||
					cur->type == 'X'))
			ft_flush(ctx, n->sign[1]);
	}
	ft_add(n, cur, ctx);
	i = 0;
	if (cur->flags.moins)
		while (i++ < cur->width - scp[0])
			ft_flush(ctx, scp[1]);
}

static void	ft_addsignox(t_ctx *ctx, t_nb *n, t_arg *cur, int *p)
{
	ft_flush(ctx, n->sign[0]);
	if (cur->flags.hash)
		ft_flush(ctx, n->sign[1]);
	*p = 1;
}

void		ft_print_nb(t_arg *cur, t_ctx *ctx, t_nb *n)
{
	int size[2];
	int scp[3];

	scp[2] = 0;
	size[1] = 0;
	if (n->val == 0 && cur->width > 1 && cur->flags.zero == 0 && !cur->flags.
		moins && (!cur->flags.hash || cur->mod == UNDEF || cur->prec == 0))
		ft_flush(ctx, ' ');
	n->sign = ft_sign(n->sign, cur, &size[1], n->val);
	size[0] = ft_max(ft_sizenb(n->val, n->base), cur->prec);
	size[1] = (n->sign[0] != 0) ? size[1] + 1 : size[1];
	scp[1] = (cur->flags.zero && cur->flags.moins == 0 && cur->prec == -1) ?
		'0' : ' ';
	if (scp[1] == '0' && n->sign[0] != 0 && ft_isnot_ten(cur->type) == 0)
		ft_flush(ctx, n->sign[0]);
	if ((cur->type == 'x' || cur->type == 'X') && n->sign[0] != 0 &&
			cur->flags.zero && cur->prec != 0)
		ft_addsignox(ctx, n, cur, &scp[2]);
	else if ((cur->flags.hash && ((cur->flags.zero && n->val != 0) ||
			(cur->width > 0 && cur->prec > 0)) && (cur->type == 'o' ||
			cur->type == 'O') && cur->prec != 0 && size[1] > 0) ||
			(cur->flags.moins && n->val == 0 && !cur->flags.zero))
		size[1]--;
	scp[0] = size[0] + size[1];
	ft_addtobuf(cur, ctx, n, scp);
}
