/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 09:59:15 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/05 10:39:10 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		label_char(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (1);
	return (0);
}

int		check_label(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!label_char(str[i]))
			return (0);
		i++;
	}
	return (1);
}
