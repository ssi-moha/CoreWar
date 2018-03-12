/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 13:42:14 by emerabet          #+#    #+#             */
/*   Updated: 2018/03/12 14:45:35 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_corewar.h"

#ifndef CMD_H
# define CMD_H

void			func_tab(t_cmd par, t_process *proc);
void			ft_and(t_process *proc, t_vm *vm);
void			ft_or(t_process *proc, t_vm *vm);
void			ft_xor(t_process *proc, t_vm *vm);

#endif
