/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 01:02:36 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/23 01:03:08 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
