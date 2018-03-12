/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corewar.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 09:53:57 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/12 11:27:43 by lfujimot         ###   ########.fr       */
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

# define L 1
# define A 2
# define K 4

# define	BUF_SIZE	1024
# define	EXT_FILE	".s"
# define	EXT_COR		".cor"

int g_arg;

typedef enum		e_cmd
{
	DEFAULT,
	LIVE,
	LD,
	ST,
	ADD,
	SUB,
	AND,
	OR,
	XOR,
	ZJMP,
	LDI,
	STI,
	FORK,
	LLD,
	LLDI,
	LFORK,
	AFF
}					t_cmd;

typedef struct		s_par
{
	char			*par;
	int				type;
	struct s_par	*next;
}					t_par;

//TYPE:
//REG = 1
//DIR = 2
//DIR + LAB = 2 + 8 = 10
//IND = 4
//IND + LAB = 4 + 8 = 12

typedef struct		s_process
{
	int				id;
	unsigned char	r[REG_NUMBER][REG_SIZE]; //id stocke dans r1
	int				pc;
	short			carry;
	int				cycle;
	int				inlive;
	enum e_cmd		cmd;
	unsigned char	partype[3];
	int				par[3];
	struct s_process	*next;
}					t_process;

typedef struct		s_player
{
	t_header		header;
	unsigned int	id;
	unsigned int	number; // a rajouter pour le dislay
	unsigned int	startpos;
	struct s_player	*next;
}					t_player;

typedef struct		s_vm
{
	unsigned char	ram[MEM_SIZE];
	t_process		*processes;
	t_player		*players;
	int				curcycle;
	int				cyclelimit;
	int				start;
	unsigned int	totalprocess;
}					t_vm;

typedef struct		s_instr
{
	char			*cmd;
	char			*label;
	unsigned int	sizeoctet;
	t_par			*params;
	struct s_instr	*next;
}					t_instr;

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
	struct s_op		*next;
}					t_op;

typedef struct		s_app // structure globale de l'application
{
	t_instr			*instr;
	t_header		header;
	int				checkcmd;
}					t_app;

typedef struct		s_args
{
	int				dump;
	int				nb;
	int				champion[4];
	int				isvalid;
}					t_args;

extern	t_op		g_optab[17];
int					ft_isincharset(char c, char *charset);
int					free_par(t_par **par);
t_par				*new_par(char *par, t_par **prev);
t_instr				*new_instr(char *cmd, t_instr **prev);
int					free_instr(t_instr **instr);
int					skip_cmt(char *str);
int					ft_parselabel(char *line, t_instr *new);
int					ft_parseinstr(char *line, int pos, t_instr *new);
void				ft_parseparams(char *line, int pos, t_instr *new);
int					ft_skip_com_and_blank(char *line);
int					check_name_cmt(char *str);
int					cpy_head(int ret, t_header *head, char **line);
int					ft_checkparams(char *par);
int					ft_findcmd(char *cmd);
int					error_mess(char *str);
int					make_pos(char **line, t_instr *new, t_par *tmp);
int					rm_process(int id, t_process **proc);
int					ft_convertheader(t_app *application, char **file_name);
void				ft_converttohex(t_instr *instr);
void				free_proc(t_process **proc);
void				ft_printhex(t_instr *instr, int out);
int					prog_size(t_instr **instr);
unsigned int		count_label(t_instr **instr, t_instr **begin, char *label,
		int cmd);
void				ft_printsizepar(t_instr *instr, int out);
void				ft_printdiril(unsigned int lab, int cmd, int out);
void				ft_printdir(t_par *par, int cmd, int out);
void				ft_printindlab(t_par *par, t_instr **begin, t_instr **instr,
		int out);


//open_filescor
//checkvalidfile magic + prog size
//getname
//getcomment
//setid player
//create process
//getbytecode ram
//
unsigned char			*ft_openfile(char *file);
int				ft_check_filename(char *str, char *extension);
void			ft_checkmagic(unsigned char *data);
unsigned int			ft_checkprogsize(unsigned char *data);
void			ft_loadinram(unsigned char *data, unsigned int nbplayers, t_vm *vm, t_player *p);
void			ft_setname(unsigned char *data, t_header *header);
void			ft_setcomment(unsigned char *data, t_header *header);
t_player		*new_player(unsigned char *data, t_player **prev, unsigned int id);
void			ft_showram(unsigned char *ram);
t_process		*new_process(t_player *player, t_process **prev, t_vm *vm);
void			ft_startvm(t_vm *vm);
void			ft_loadnewinstr(t_process *p, t_vm *vm);
void			ft_setint(int *tab, int value, unsigned int size);
t_args			ft_parse_arg(int argc, char **argv);
#endif
