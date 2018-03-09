/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_filename.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 18:02:31 by emerabet          #+#    #+#             */
/*   Updated: 2018/03/09 18:29:15 by emerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		ft_check_filename(char *str, char *extension)
{
	int		len;
	int		lenext;
	int		res;

	if (str == NULL || extension == NULL)
		return (-1);
	len = ft_strlen(str);
	lenext = ft_strlen(extension);
	res = ft_strcmp(str + (len - lenext), extension);
	if (res == 0)
		return (1);
	return (-1);
}
