/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 01:02:36 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/08 21:48:06 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_init_map(char *map)
{
	int	count;

	count = 0;
	if (!(map = (char *)malloc(sizeof(char) * 16 * 16 + 1)))
		return (NULL);
	while (count <= (16 * 16))
	{
		map[count] = '.';
		count++;
	}
	map[count] = '\0';
	return (map);
}

int		main(int argc, char *argv[])
{
	int		i;
	t_etri	*tab;
	t_etri	tetri;
	t_list	*list;
	char	*map;

	i = 0;
	if (!(tab = (t_etri *)malloc(sizeof(t_etri *) * 26)))
		tab = NULL;
	list = NULL;
	list = ft_read_file(argv[1], &i);
	map = NULL;
	map = ft_init_map(map);
	if (i == -1)
		return (-1);
	while (list)
	{
		if (ft_is_valid((char *)list->content))
		{
			tetri = ft_create_tetri((char *)list->content);
			ft_set_in_corner(&tetri, (char *)list->content);
			i = ft_push_back_tetri(&tab, tetri);
		}
		else
		{
			ft_putstr_fd("unvalid file (2)\n", 2);
			return (-1);
		}
		list = list->next;
	}
	while (i--)
		ft_print_tetri(tab[i]);
	argc++;
	return (0);
}
