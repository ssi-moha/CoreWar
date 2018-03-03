/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraytolst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:34:47 by lfujimot          #+#    #+#             */
/*   Updated: 2018/02/15 12:34:49 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

t_list		*ft_arraytolst(char **arr)
{
	t_list	*list;
	int		i;

	list = NULL;
	i = 0;
	while (arr[i])
	{
		ft_lstpushback(&list, arr[i], ft_strlen(arr[i]));
		i++;
	}
	return (list);
}
