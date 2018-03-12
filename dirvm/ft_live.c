/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 11:39:09 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/12 12:00:33 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

void	ft_live(int par[3], t_process *proc, t_vm vm)
{
	t_process *tmp;

	tmp = vm.processes;
	while (tmp && tmp->id != par[0])
		tmp = tmp->next;
	tmp->inlive = 1;
	vm.nblive++;
}
