/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:37:41 by lfujimot          #+#    #+#             */
/*   Updated: 2018/02/15 12:37:42 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_lstcount(t_list **alst)
{
	t_list	*current;
	size_t	count;

	current = *alst;
	count = 0;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
