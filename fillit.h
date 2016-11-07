/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 23:22:30 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/07 18:04:56 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 20

# include <stdio.h>
# include <fcntl.h>
# include "../../libft/libft.h"

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_etri
{
	char				c;
	int					width;
	int					height;
	t_point				pos;
	t_point				blocs[4];
	t_point				top;
	t_point				bottom;
}						t_etri;

void					ft_print_list(t_list *lst);
t_list					*ft_read_file(char *name, int *err);
int						ft_is_valid(char *str);
int						ft_get_width(const char *str);
int						ft_get_height(const char *str);

#endif
