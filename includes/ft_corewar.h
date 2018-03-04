/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corewar.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:02:23 by lfujimot          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/03/03 18:54:51 by lfujimot         ###   ########.fr       */
=======
/*   Updated: 2018/03/03 18:22:55 by ssi-moha         ###   ########.fr       */
>>>>>>> refs/remotes/origin/master
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COREWAR_H
# define FT_COREWAR_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../printf/includes/ft_printf.h"
<<<<<<< HEAD
# include "op.h"

=======
# include <stdio.h>
>>>>>>> refs/remotes/origin/master
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
<<<<<<< HEAD
int					ft_isincharset(char c, char *charset);
int					ft_free_par(t_par **par);
void				new_par(char *par, t_par **prev);
t_instr				*new_instr(char *cmd, t_instr **prev);
int					free_instr(t_instr **instr);
int					ft_parselabel(char *line, t_instr *new);
=======

int		free_par(t_par **par);
void	new_par(char *par, t_par **prev);
void	new_instr(char *cmd, t_instr **prev);
int		free_instr(t_instr **instr);
>>>>>>> refs/remotes/origin/master
#endif
