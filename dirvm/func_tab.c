/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:13:51 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/12 15:18:51 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void	func_tab(t_cmd par, t_process *proc, t_vm *vm)
{
	static void		(*tab[17])(t_process *proc, t_vm *vm);
//	tab[0] = ft_default;
//	tab[1] = ft_live;
//	tab[2] = ft_ld;
//	tab[3] = ft_st;
//	tab[4] = ft_add;
//	tab[5] = ft_sub;
	tab[6] = ft_and;
	tab[7] = ft_or;
	tab[8] = ft_xor;
//	tab[9] = ft_zjmp;
//	tab[10] = ft_ldi;
//	tab[11] = ft_sti;
//	tab[12] = ft_fork;
//	tab[13] = ft_lld;
//	tab[14] = ft_lldi;
//	tab[15] = ft_lfork;
//	tab[16] = ft_aff;
	tab[(int)par](proc, vm);
}
