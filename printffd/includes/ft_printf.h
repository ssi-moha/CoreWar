/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 11:00:26 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/10 17:36:51 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFF_SIZE 4096
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct		s_ctx
{
	char			buf[BUFF_SIZE];
	unsigned int	pos;
	const char		*format;
	int				fd;
	unsigned int	size;
}					t_ctx;

typedef struct		s_nb
{
	uintmax_t		val;
	int				base;
	char			*sign;
}					t_nb;

typedef enum		e_mod
{
	NONE,
	HH,
	H,
	L,
	LL,
	Z,
	J,
	UNDEF
}					t_mod;

typedef struct		s_flag
{
	int				moins;
	int				plus;
	int				zero;
	int				space;
	int				hash;

}					t_flag;

typedef struct		s_arg
{
	char			type;
	t_flag			flags;
	int				width;
	int				prec;
	t_mod			mod;
	int				endpos;
}					t_arg;

int					ft_printf(const char *format, ...);
int					ft_manage_type(t_arg *current, va_list va, t_ctx *ctx);
int					ft_istype(char c);
int					ft_isflag(char c);
int					ft_ischarflag(char c);
int					ft_atoi_sp(const char *str, int pos);
int					ft_ismod(char c);
void				ft_parse(t_arg *current, int i, t_ctx *ctx);
void				ft_forchar(char c, t_arg *current, t_ctx *ctx);
int					ft_forchar_uni(wchar_t c, t_arg *current, t_ctx *ctx);
void				ft_forstr(char *str, t_arg *current, t_ctx *ctx);
void				ft_forstr_uni(wchar_t *str, t_arg *current, t_ctx *ctx);
void				ft_warning(char t, char type, char n);
void				ft_itoa_base_sp(t_nb *n, char type, t_ctx *ctx,
					t_arg *current);
void				ft_fornb(uintmax_t nb, t_arg *current, t_ctx *ctx,
					char sign[2]);
void				ft_intmaxt(intmax_t nb, t_arg *current, t_ctx *ctx);
int					ft_isnot_ten(char c);
void				ft_uintmaxt(uintmax_t nb, t_arg *current, t_ctx *ctx);
int					ft_sizenb(uintmax_t value, int base);
void				ft_flush(t_ctx *ctx, char c);
void				ft_forpp(uintptr_t p, t_arg *current, t_ctx *ctx);
void				ft_print_nb(t_arg *cur, t_ctx *ctx, t_nb *n);
int					ft_max(int a, int b);
int					ft_isdigit(int c);
#endif
