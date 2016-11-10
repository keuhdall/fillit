/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:57:05 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/10 18:15:34 by lmarques         ###   ########.fr       */
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

int		ft_check_pos(char *map, t_etri tetri)
{
	int	count;

	count = 0;
	while (count < 4)
	{
		if (map[((tetri.blocs[count].y + tetri.offset.y) * 16) +
				(tetri.blocs[count].x + tetri.offset.x)] != '.')
			return (0);
		count++;
	}
	return (1);
}

void	ft_delete_tetri(char *map, t_etri *tetri)
{
	int	count;

	count = 0;
	while (count < 4)
	{
		map[((tetri->blocs[count].y + tetri->offset.y) * 16) +
			(tetri->blocs[count].x + tetri->offset.x)] = '.';
		count++;
	}
}

void	ft_set_in_map(char *map, t_etri tetri)
{
	int	count;

	count = 0;
	while (count < 4)
	{
		map[((tetri.blocs[count].y + tetri.offset.y) * 16) +
			(tetri.blocs[count].x + tetri.offset.x)] = tetri.c;
		count++;
	}
}

int		ft_move_tetri(char *map, t_etri *tetri, int size, int tab_size)
{
	if (tab_size == 0)
		return (1);
	tetri->offset.y = 0;
	while (tetri->offset.y <= size - tetri->height)
	{
		tetri->offset.x = 0;
		while (tetri->offset.x <= size - tetri->width)
		{
			if (ft_check_pos(map, *tetri))
			{
				ft_set_in_map(map, *tetri);
				if (ft_move_tetri(map, tetri + 1, size, tab_size - 1))
					return (1);
				ft_delete_tetri(map, tetri);
			}
			tetri->offset.x++;
		}
		tetri->offset.y++;
	}
	return (0);
}
