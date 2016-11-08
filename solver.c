/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:57:05 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/08 21:57:54 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_set_in_corner(t_etri *tetri, const char *str)
{
	int	count;
	int	count_blocs;

	count = 0;
	count_blocs = 0;
	while (count < 20)
	{
		if (str[count] == '#')
		{
			tetri->blocs[count_blocs].x = (count % 5) - tetri->min.x;
			tetri->blocs[count_blocs].y = (count / 5) - tetri->min.y;
			count_blocs++;
		}
		count++;
	}
}
