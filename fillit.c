/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 01:02:36 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/08 01:31:24 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_etri	ft_create_tetri(char *str)
{
	t_etri		tetri;
	static char	c = 'A';

	tetri.c = c;
	tetri.width = ft_get_width(str);
	tetri.height = ft_get_height(str);
	tetri.pos = ft_get_pos(str);
	tetri.blocs = ft_get_blocs(str);
	c++;
	return (tetri);
}

int		main(int argc, char *argv[])
{
	int		err;
	t_list	*list;

	err = 0;
	list = NULL;
	list = ft_read_file(argv[1], &err);
	if (err != -1)
		ft_print_list(list);
	argc++;
	return (0);
}
