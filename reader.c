/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 03:46:08 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/08 14:00:28 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_tetri(t_etri tetri)
{
	printf("char : %c\n", tetri.c);
	printf("height : %d, width : %d\n", tetri.height, tetri.width);
	printf("pos : %d;%d\n", tetri.pos.x, tetri.pos.y);
	for (int i = 0; i <= 3; i++) {
		printf("pos bloc[%d], %d;%d\n", i, tetri.blocs[i].x, tetri.blocs[i].y);
	}
	printf("min : %d;%d max : %d;%d\n", tetri.min.x, tetri.min.y, tetri.max.x, tetri.max.y);
	ft_putchar('\n');
}

t_list	*ft_read_file(char *name, int *err)
{
	int		fd;
	int		ret;
	char	buffer[BUFF_SIZE + 1];
	char	buffer_empty_line[1];
	t_list	*list;

	list = NULL;
	fd = open(name, O_RDONLY);
	while (1)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		if (ret != 0 && ret != BUFF_SIZE && buffer_empty_line[0] != '\n')
		{
			ft_putstr("unvalid file 1\n");
			*err = -1;
			break ;
		}
		if (ret == 0)
			break ;
		buffer[ret] = '\0';
		ft_lst_push_back(&list, ft_lstnew(buffer, BUFF_SIZE));
		ret = read(fd, buffer_empty_line, 1);
	}
	return (list);
}
