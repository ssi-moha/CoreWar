/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 15:14:41 by lfujimot          #+#    #+#             */
/*   Updated: 2017/12/16 10:52:00 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_printf.h"

void	ft_forchar(char c, t_arg *current, t_ctx *ctx)
{
	int		i;
	char	w;

	if (current->flags.zero)
		w = '0';
	else
		w = ' ';
	i = -1;
	if (!current->flags.moins)
		while (++i < current->width - 1)
			ft_flush(ctx, w);
	ft_flush(ctx, c);
	i = -1;
	if (current->flags.moins)
		while (++i < current->width - 1)
			ft_flush(ctx, ' ');
}
