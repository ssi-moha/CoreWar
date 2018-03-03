/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremovefirst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 12:39:34 by lfujimot          #+#    #+#             */
/*   Updated: 2018/02/15 12:39:37 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	ft_lstremovefirst(t_list **alst)
{
	t_list	*next;

	if (*alst != NULL)
	{
		next = (*alst)->next;
		free(*alst);
		*alst = next;
	}
}
