/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 03:46:08 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/11 13:50:22 by cprouveu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_reader(int ret, char c, int **err)
{
	if (ret != BUFF_SIZE && c != '\n')
	{
		**err = -1;
		return (1);
	}
	if (ret == 0)
		return (1);
	return (0);
}

t_list	*ft_read_file(char *name, int *err)
{
	int		fd;
	int		ret[2];
	char	buffer[BUFF_SIZE + 1];
	char	buffer_empty_line[1];
	t_list	*list;

	list = NULL;
	fd = open(name, O_RDONLY);
	while ((ret[0] = read(fd, buffer, BUFF_SIZE)))
	{
		if (ft_check_reader(ret[0], buffer_empty_line[0], &err))
			break ;
		buffer[ret[0]] = '\0';
		ft_lst_push_back(&list, ft_lstnew(buffer, BUFF_SIZE));
		ret[1] = read(fd, buffer_empty_line, 1);
	}
	if (ret[1] == 1 || *err == -1)
	{
		*err = -1;
		ft_putendl("error");
	}
	return (list);
}
