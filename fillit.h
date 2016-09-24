/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 23:22:30 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/24 02:11:36 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 20

# include <stdio.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_etrimino
{
	char	*content;
	int		x;
	int		y;
	int		height;
	int		length;
}				t_etrimino;

void			ft_lst_push_back(t_list **begin_list, t_list *elem);
void			ft_print_list(t_list *lst);
t_list			*ft_read_file(char *name, int *err);
int				ft_count_blocks(char *str);
int				ft_is_valid(char *str);
int				ft_get_height(char *str);
int				ft_get_length(char *str);

#endif
