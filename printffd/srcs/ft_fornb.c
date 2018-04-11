/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fornb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:11:42 by lfujimot          #+#    #+#             */
/*   Updated: 2017/12/16 19:42:04 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_fornb(uintmax_t nb, t_arg *current, t_ctx *ctx, char sign[2])
{
	int			i;
	t_nb		n;

	n.val = nb;
	n.sign = sign;
	i = 0;
	if (current->type == 'o' || current->type == 'O')
		n.base = 8;
	else if (current->type == 'x' || current->type == 'X')
		n.base = 16;
	else
		n.base = 10;
	ft_print_nb(current, ctx, &n);
}
