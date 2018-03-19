/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 10:08:12 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/19 10:22:41 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		rm_process(int id, t_process **proc)
{
	t_process	*tmp;
	t_process	*del;
	t_process	*last;

	tmp = *proc;
	if (tmp->id == id)
	{
		*proc = tmp->next;
		free(tmp);
		return (1);
	}
	while (id != tmp->next->id)
		tmp = tmp->next;
	del = tmp->next;
	last = tmp->next->next;
	tmp->next = last;
	free(del);
	return (1);
}


