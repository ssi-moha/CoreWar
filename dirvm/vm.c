/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfujimot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 12:48:57 by lfujimot          #+#    #+#             */
/*   Updated: 2018/03/10 10:57:23 by lfujimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_corewar.h"

int		main(int argc, char **argv)
{
	unsigned char	*data;

	if (argc < 2)
		return (0);
	if (ft_check_filename(argv[1], EXT_COR) == -1)
		exit(error_mess("Wrong filename\n"));
	data = ft_openfile(argv[1]);
	if (data != NULL)
	{
		ft_checkmagic(data);
		ft_checkprogsize(data);
	}
}
