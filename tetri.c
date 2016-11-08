/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 01:16:48 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/08 01:33:52 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_get_height(const char *str)
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

int		ft_get_width(const char *str)
{
	int	count;
	int	count_width;

	count = 0;
	count_width = 0;
	while (count <= 4)
	{
		if (str[count] == '#' || str[count + 5] == '#' ||
			str[count + 10] == '#' || str[count + 15] == '#')
			count_width++;
		count++;
	}
	return (count_width);
}

t_point	ft_get_pos(const char *str)
{
	int		count;
	t_point	pos;

	count = 0;
	while (str[count])
	{
		if (str[count] == '#')
		{
			pos.x = count % 5;
			pos.y = count / 5; // COULD BE WRONG !
			return (pos);
		}
		count++;
	}
	pos.x = 0;
	pos.y = 0;
	return (pos);
}

t_point	*ft_get_blocs(const char *str)
{
	t_point			*bloc;
	int				count_str;
	int				count_blocs;

	count_str = 0;
	count_blocs = 0;
	while (str[count_str])
	{
		if (str[count_str] == '#')
		{
			bloc[count_blocs].x = count_str % 5;
			bloc[count_blocs].y = (count_str / 5); // COULD BE WRONG !
			count_blocs++;
		}
		count_str++;
	}
	return (bloc);
}
