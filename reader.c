/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 03:46:08 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/10 19:05:04 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
