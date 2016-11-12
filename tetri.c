/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 01:16:48 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/12 11:36:35 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_get_size(const char *str, int *height, int *width)
{
	int	count;
	int	swap;

	count = 0;
	swap = 0;
	*height = 0;
	*width = 0;
	while (count < 20)
	{
		if (str[count] && str[count] == '#' && swap == 0)
		{
			(*height)++;
			swap = 1;
		}
		if (str[count] == '\n')
			swap = 0;
		count++;
	}
	count = -1;
	while (++count <= 4)
	{
		if (str[count] == '#' || str[count + 5] == '#' ||
			str[count + 10] == '#' || str[count + 15] == '#')
			(*width)++;
	}
}

t_point	*ft_get_blocs(const char *str)
{
	t_point	*bloc;
	int		count_str;
	int		count_blocs;

	if (!(bloc = (t_point *)malloc(sizeof(t_point) * 4)))
		bloc = NULL;
	count_str = 0;
	count_blocs = 0;
	while (count_str < 20)
	{
		if (str[count_str] == '#')
		{
			bloc[count_blocs].x = count_str % 5;
			bloc[count_blocs].y = (count_str / 5);
			count_blocs++;
		}
		count_str++;
	}
	return (bloc);
}

void	ft_get_min_max(const char *str, t_point *min, t_point *max)
{
	int	count;

	count = 0;
	min->x = 3;
	min->y = 3;
	max->x = 0;
	max->y = 0;
	while (count < 20)
	{
		if (str[count] == '#')
		{
			if (count % 5 < min->x)
				min->x = count % 5;
			if (count / 5 < min->y)
				min->y = count / 5;
			if (count % 5 > max->x)
				max->x = count % 5;
			if (count / 5 > max->y)
				max->y = count / 5;
		}
		count++;
	}
}

int		ft_push_back_tetri(t_etri **tab, t_etri tetri)
{
	static int	count = 0;

	if (count <= 25)
	{
		(*tab)[count] = tetri;
		count++;
	}
	return (count);
}

t_etri	ft_create_tetri(const char *str)
{
	t_etri		tetri;
	static char	c = 'A';

	tetri.c = c;
	tetri.offset.x = 0;
	tetri.offset.y = 0;
	ft_get_size(str, &tetri.height, &tetri.width);
	ft_get_min_max(str, &tetri.min, &tetri.max);
	tetri.blocs = ft_get_blocs(str);
	c++;
	return (tetri);
}
