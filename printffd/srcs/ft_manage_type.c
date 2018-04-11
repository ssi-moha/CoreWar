/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:34:37 by lfujimot          #+#    #+#             */
/*   Updated: 2017/12/17 16:10:29 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_di(t_arg *current, va_list va, t_ctx *ctx)
{
	if (current->type == 'D')
		ft_intmaxt(va_arg(va, long), current, ctx);
	else if (current->mod == HH)
		ft_intmaxt((signed char)va_arg(va, int), current, ctx);
	else if (current->mod == H)
		ft_intmaxt((short)va_arg(va, int), current, ctx);
	else if (current->mod == L)
		ft_intmaxt(va_arg(va, long), current, ctx);
	else if (current->mod == LL)
		ft_intmaxt(va_arg(va, long long), current, ctx);
	else if (current->mod == J)
		ft_intmaxt(va_arg(va, intmax_t), current, ctx);
	else if (current->mod == Z)
		ft_intmaxt(va_arg(va, size_t), current, ctx);
	else
		ft_intmaxt(va_arg(va, int), current, ctx);
}

static void	ft_oxu(t_arg *current, va_list va, t_ctx *ctx)
{
	if (current->type == 'U')
		ft_uintmaxt((uintmax_t)va_arg(va, unsigned long), current, ctx);
	else if (current->type == 'O')
		ft_uintmaxt((uintmax_t)va_arg(va, unsigned long), current, ctx);
	else if (current->mod == HH)
		ft_uintmaxt((unsigned char)va_arg(va, int), current, ctx);
	else if (current->mod == H)
		ft_uintmaxt((unsigned short)va_arg(va, int), current, ctx);
	else if (current->mod == LL)
		ft_uintmaxt(va_arg(va, unsigned long long), current, ctx);
	else if (current->mod == L)
		ft_uintmaxt((uintmax_t)va_arg(va, unsigned long), current, ctx);
	else if (current->mod == J)
		ft_uintmaxt(va_arg(va, uintmax_t), current, ctx);
	else if (current->mod == Z)
		ft_uintmaxt(va_arg(va, size_t), current, ctx);
	else
		ft_uintmaxt((unsigned int)va_arg(va, int), current, ctx);
}

int			ft_manage_type(t_arg *current, va_list va, t_ctx *ctx)
{
	if (current->type == '%')
		ft_forchar('%', current, ctx);
	else if (current->type == 'C' || (current->type == 'c' &&
			current->mod == L))
		return (ft_forchar_uni(va_arg(va, wchar_t), current, ctx));
	else if (current->type == 'S' || (current->type == 's' &&
			current->mod == L))
		ft_forstr_uni(va_arg(va, wchar_t*), current, ctx);
	else if (current->type == 'c')
		ft_forchar(va_arg(va, int), current, ctx);
	else if (current->type == 's')
		ft_forstr(va_arg(va, char*), current, ctx);
	else if (current->type == 'o' || current->type == 'O' ||
			current->type == 'x' || current->type == 'X' ||
			current->type == 'u' || current->type == 'U')
		ft_oxu(current, va, ctx);
	else if (current->type == 'd' || current->type == 'i' ||
			current->type == 'D')
		ft_di(current, va, ctx);
	else if (current->type == 'p')
		ft_forpp(va_arg(va, uintptr_t), current, ctx);
	return (0);
}
