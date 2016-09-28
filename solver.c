/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 01:16:48 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/29 00:40:23 by lmarques         ###   ########.fr       */
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
