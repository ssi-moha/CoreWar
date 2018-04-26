/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:42:50 by lfujimot          #+#    #+#             */
/*   Updated: 2018/04/26 17:44:00 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int	ft_type_value(int dir, int lab)
{
	if (dir == 1 && lab == 0)
		return (T_DIR);
	else if (dir == 1 && lab == 1)
		return (T_DIR + T_LAB);
	else if (dir == 0 && lab == 0)
		return (T_IND);
	else if (dir == 0 && lab == 1)
		return (T_IND + T_LAB);
	return (-1);
}
