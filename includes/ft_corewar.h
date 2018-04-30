/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corewar.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 09:53:57 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/27 17:59:59 by lfujimot         ###   ########.fr       */
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
# include <limits.h>
# define BUF_SIZE	1024
# define EXT_FILE	".s"
# define EXT_COR	".cor"

int g_arg;

typedef enum				e_cmd
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
}							t_cmd;

typedef struct				s_par
{
	char					*par;
	int						type;
	struct s_par			*next;
}							t_par;

typedef struct				s_process
{
	int						id;
	unsigned char			r[REG_NUMBER][REG_SIZE];
	int						pc;
	int						lastpc;
	int						playernb;
	short					carry;
	int						cycle;
	int						inlive;
	enum e_cmd				cmd;
	int						num;
	unsigned char			partype[3];
	int						par[3];
	struct s_process		*next;
}							t_process;

typedef struct				s_player
{
	t_header				header;
	unsigned int			id;
	int						inlive;
	int						nblive;
	int						number;
	unsigned int			num;
	unsigned int			startpos;
	struct s_player			*next;
}							t_player;

typedef struct				s_args
{
	int						dump;
	int						nb;
	int						visu;
	int						verb;
	int						live;
	int						champion[4];
	int						posfile[4];
	int						isvalid;
}							t_args;

typedef struct				s_vm
{
	unsigned char			ram[MEM_SIZE];
	unsigned char			ramplayer[MEM_SIZE];
	t_process				*processes;
	t_player				*players;
	int						curcycle;
	int						cyclelimit;
	int						cycletotal;
	int						start;
	int						nblive;
	int						maxchecks;
	unsigned int			incplayer;
	unsigned int			totalprocess;
	t_args					args;
	int						lastlive;
}							t_vm;

typedef struct				s_lab
{
	char					*l;
	struct s_lab			*next;
}							t_lab;

typedef struct				s_instr
{
	char					*cmd;
	t_lab					*label;
	unsigned int			sizeoctet;
	t_par					*params;
	struct s_instr			*next;
}							t_instr;

typedef struct				s_op
{
	char					*cmd;
	int						nbpar;
	int						typepar[3];
	int						numcmd;
	int						nbcycle;
	char					*descr;
	int						octpar;
	int						dirsize;
}							t_op;

typedef struct				s_app
{
	t_instr					*instr;
	t_header				header;
	t_lab					*tmplab;
	int						checkcmd;
}							t_app;

extern	t_op				g_optab[17];
int							ft_isincharset(char c, char *charset);
int							free_par(t_par **par);
t_par						*new_par(char *par, t_par **prev);
t_instr						*new_instr(char *cmd, t_instr **prev);
int							free_instr(t_instr **instr);
int							skip_cmt(char *str);
int							ft_parselabel(char *line, t_instr *new);
int							ft_parseinstr(char *line, int pos, t_instr *new);
void						ft_parseparams(char *line, int pos, t_instr *new);
int							ft_skip_com_and_blank(char *line);
int							check_name_cmt(char *str);
int							cpy_head(int ret, t_header *head, char **line);
int							ft_checkparams(char *par);
int							ft_findcmd(char *cmd);
int							error_mess(char *str);
int							make_pos(char **line, t_instr *new);
int							rm_process(int id, t_process **proc);
int							ft_convertheader(t_app *application,
							char **file_name);
void						ft_converttohex(t_instr *instr);
void						free_proc(t_process **proc);
void						ft_printhex(t_instr *instr, int out);
int							prog_size(t_instr **instr);
unsigned int				count_label(t_instr **instr, t_instr **begin,
							char *label, int cmd);
void						ft_printsizepar(t_instr *instr, int out);
void						ft_printdiril(unsigned int lab, int cmd, int out);
void						ft_printdir(t_par *par, int cmd, int out);
void						ft_printindlab(t_par *par, t_instr **begin,
							t_instr **instr, int out);
t_lab						*new_label(char *l, t_lab **prev);
int							ft_labonly(t_app *app, char *line);
int							ft_type_value(int dir, int lab);
int							ft_checkpartype(t_par *par, int parindex,
							char *cmd);
unsigned char				*ft_openfile(char *file);
int							ft_check_filename(char *str, char *extension);
void						ft_checkmagic(unsigned char *data);
unsigned int				ft_checkprogsize(unsigned char *data);
void						ft_loadinram(unsigned char *data,
							unsigned int nbplayers, t_vm *vm, t_player *p);
void						ft_setname(unsigned char *data, t_header *header);
void						ft_setcomment(unsigned char *data,
							t_header *header);
t_player					*new_player(unsigned char *data, t_player **prev,
							unsigned int id, t_vm *vm);
void						ft_showram(unsigned char *ram);
void						ft_showramplayer(unsigned char *ram, t_vm *vm,
							int out, char *winner);
void						ft_showplayer(unsigned char *ram);
t_process					*new_process(t_player *player, t_vm *vm);
void						ft_startvm(t_vm *vm);
void						ft_loadnewinstr(t_process *p, t_vm *vm);
void						ft_setint(int *tab, int value, unsigned int size);
void						ft_checkinlive(t_process **ps, t_vm *vm);
t_args						ft_parse_arg(int argc, char **argv);
int							ft_uchar_toint(unsigned char tab[REG_SIZE]);
int							ft_getparvalue(t_process *proc, t_vm *vm, int i,
							int mod);
int							cnt_char(char *str, char c);
char						*join_lines(int fd, char *line);
int							free_lab(t_lab **lab);
void						ft_parseasm(t_instr **instr, int fd,
							t_header *head, t_app *app);
void						func_tab(t_cmd par, t_process *proc, t_vm *vm);
int							ft_live(t_process *proc, t_vm *vm);
int							ft_and(t_process *proc, t_vm *vm);
int							ft_or(t_process *proc, t_vm *vm);
int							ft_xor(t_process *proc, t_vm *vm);
void						ft_writeinreg(t_process *p, int regnnb,
							unsigned int nb);
int							ft_fork(t_process *proc, t_vm *vm);
int							ft_lfork(t_process *proc, t_vm *vm);
int							ft_add(t_process *proc, t_vm *vm);
int							ft_sub(t_process *proc, t_vm *vm);
int							ft_ld(t_process *proc, t_vm *vm);
int							ft_lld(t_process *proc, t_vm *vm);
int							ft_ldi(t_process *proc, t_vm *vm);
int							ft_lldi(t_process *proc, t_vm *vm);
int							ft_sub(t_process *proc, t_vm *vm);
int							ft_zjmp(t_process *proc, t_vm *vm);
int							ft_sti(t_process *proc, t_vm *vm);
int							ft_st(t_process *proc, t_vm *vm);
int							ft_aff(t_process *proc, t_vm *vm);

void						ft_writeinram(t_vm *vm, unsigned int pos,
							unsigned int value, t_process *p);
unsigned int				ft_readinram(t_vm *vm, unsigned int pos,
							unsigned int nboctet);
void						ft_checkplayerinlive(t_player **p);
void						ft_resetplayerinlive(t_player **p);
void						ft_winner(t_vm *vm, int out);
int							ft_printffd(int fd, const char *format, ...);
char						*ft_get_next_arg(char **argv, int argc, int key);
int							ft_hasvisu(char **argv, int key);
int							ft_hasverb(char **argv, int key);
int							ft_haslive(char **argv, int key);
int							ft_check_champion(char **argv, int argc,
							t_args *args, int key);
void						ft_visu(t_vm *vm, int out, char *winner);
void						ft_nextcycle(t_vm *vm);
#endif
