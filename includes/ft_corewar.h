/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corewar.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:02:23 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/03 18:22:55 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COREWAR_H
# define FT_COREWAR_H
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../printf/includes/ft_printf.h"
# include <stdio.h>
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

int		free_par(t_par **par);
void	new_par(char *par, t_par **prev);
void	new_instr(char *cmd, t_instr **prev);
int		free_instr(t_instr **instr);
#endif
