/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:13:24 by lfujimot          #+#    #+#             */
/*   Updated: 2018/05/10 15:23:38 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int	ft_aff(t_process *proc, t_vm *vm)
{
	unsigned int	value;

	value = ft_getparvalue(proc, vm, 0, MEM_SIZE);
	ft_printffd(1, "%c", value % 256);
	return (1);
}
