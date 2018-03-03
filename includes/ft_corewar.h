/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corewar.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:02:23 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/03 17:38:11 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COREWAR_H
# define FT_COREWAR_H
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../printf/includes/ft_printf.h"
typedef struct		s_par
{
	char			*par;
	struct s_par	*next;
}					t_par;

typedef struct		s_instr
{
	char			*cmd;
	char			*label;
	t_par			*params;
	struct s_instr	*next;
}					t_instr;
#endif
