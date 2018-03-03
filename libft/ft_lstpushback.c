/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:39:04 by lfujimot          #+#    #+#             */
/*   Updated: 2018/02/15 12:39:05 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstpushback(t_list **begin, void *content, size_t content_size)
{
	t_list *new;

	new = *begin;
	if (new)
	{
		while (new->next)
			new = new->next;
		new->next = ft_lstnew(content, content_size);
	}
	else
		*begin = ft_lstnew(content, content_size);
}
