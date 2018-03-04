/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corewar.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 09:53:57 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/04 16:40:14 by lfujimot         ###   ########.fr       */
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
# include "op.h"
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

typedef struct		s_app // structure globale de l'application
{
	t_instr			*instr;
	char			name[100]; // default size to check
	char			comment[100]; // default size to check
}					t_app;

typedef struct		s_op
{
	char			*cmd;
	int				nbpar;
	int				typepar[3];
	int				numcmd;
	int				nbcycle;
	char			*descr;
	int				octpar; //octet de codage des parametres
	int				dirsize; //1 = 2 0 = 4
}					t_op;

int					ft_isincharset(char c, char *charset);
int					free_par(t_par **par);
t_par				*new_par(char *par, t_par **prev);
t_instr				*new_instr(char *cmd, t_instr **prev);
int					free_instr(t_instr **instr);
int					ft_parselabel(char *line, t_instr *new);
int					ft_parseinstr(char *line, int pos, t_instr *new);
void				ft_parseparams(char *line, int pos, t_instr *new);
t_op				*ft_initop(void);
//void				ft_skipcommentandblank --> Sinane
//void				ft_managenameandcomment
//void				ft_printhex
#endif
