/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 12:00:41 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/13 13:41:33 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/ft_corewar.h"

int		ft_ld(t_process *proc, t_vm *vm)
{
	int i;

	i = ft_getparvalue(proc, vm, proc->par[0]);
	if (i > 16)
		return (0);
	ft_writeinreg(proc, proc->par[1], i);
	return (1);
}
