/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 01:16:48 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/24 02:49:44 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_get_height(char *str)
{
	int	count;
	int	count_height;
	int	swap;

	count = 0;
	count_height = 0;
	swap = 0;
	while (str[count])
	{
		if (str[count] == '#' && swap == 0)
		{
			count_height++;
			swap = 1;
		}
		if (str[count] == '\n')
			swap = 0;
		count++;
	}
	return (count_height);
}

int			ft_get_length(char *str)
{
	int	count;
	int	count_length;

	count = 0;
	count_length = 0;
	while (count <= 4)
	{
		if (str[count] == '#' || str[count + 5] == '#' ||
			str[count + 10] == '#' || str[count + 15] == '#')
			count_length++;
		count++;
	}
	return (count_length);
}

t_etrimino	ft_make_tet(char *str)
{
	t_etrimino	new_t;

	new_t.content = str;
	new_t.x = 0;
	new_t.y = 0;
	new_t.height = ft_get_height(str);
	new_t.length = ft_get_length(str);
	return (new_t);
}
