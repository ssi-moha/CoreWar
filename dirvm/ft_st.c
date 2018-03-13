/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 14:52:01 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/13 15:34:29 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		ft_st(t_process *proc, t_vm *vm)
{
	int i;

	i = ft_getparvalue(proc, vm, proc->par[0]);
	vm->ram[proc->pc + (proc->par[1] % IDX_MOD)] = (unsigned char)i;
	return (1);
}
