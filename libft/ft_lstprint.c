/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:38:52 by lfujimot          #+#    #+#             */
/*   Updated: 2018/02/15 12:38:54 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstprint(t_list *list)
{
	t_list	*current;
	char	*str;

	current = list;
	while (current)
	{
		str = (char *)current->content;
		ft_putendl(str);
		current = current->next;
	}
}
