/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 01:02:36 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/12 11:56:36 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_init_map(char *map)
{
	int	count;

	count = 0;
	if (!(map = (char *)malloc(sizeof(char) * 16 * 16 + 1)))
		return (NULL);
	while (count <= (16 * 16 - 1))
	{
		map[count] = '.';
		count++;
	}
	map[count] = '\0';
	return (map);
}

void	ft_print_map(char *map, int size)
{
	int	count;
	int	count2;

	count = 0;
	while (count < size)
	{
		count2 = 0;
		while (count2 < size)
		{
			ft_putchar(map[(count * 16) + count2]);
			count2++;
		}
		ft_putchar('\n');
		count++;
	}
}

int		ft_init(t_list *list, t_etri **tab, int *i)
{
	t_etri	tetri;

	if (*i == -1)
	{
		ft_putendl("error");
		return (0);
	}
	while (list)
	{
		if (ft_is_valid((char *)list->content))
		{
			tetri = ft_create_tetri((char *)list->content);
			ft_set_in_corner(&tetri, (char *)list->content);
			*i = ft_push_back_tetri(*(&tab), tetri);
		}
		else if (!ft_is_valid((char *)list->content) || *i > 25)
		{
			ft_putendl("error");
			return (0);
		}
		list = list->next;
	}
	return (1);
}

void	ft_free(t_list **list, char **map, t_etri **tab)
{
	free(*list);
	free(*map);
	free(*tab);
}

int		main(int argc, char *argv[])
{
	int		i;
	int		size;
	t_etri	*tab;
	t_list	*list;
	char	*map;

	i = 0;
	if (!(tab = (t_etri *)malloc(sizeof(t_etri) * 26)))
		tab = NULL;
	list = NULL;
	list = ft_read_file(argv[1], &i);
	map = NULL;
	map = ft_init_map(map);
	if (i == -1 || !ft_init(list, &tab, &i) || argc != 2)
		return (-1);
	size = (tab[0].height > tab[0].width ? tab[0].height : tab[0].width);
	while (!ft_move_tetri(map, &tab[0], size, i))
	{
		ft_init_map(map);
		size++;
	}
	ft_print_map(map, size);
	ft_free(&list, &map, &tab);
	return (0);
}
