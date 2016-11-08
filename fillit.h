/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 23:22:30 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/08 14:02:45 by lmarques         ###   ########.fr       */
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
	t_point				*blocs;
	t_point				min;
	t_point				max;
}						t_etri;

void					ft_print_tetri(t_etri tetri);
t_list					*ft_read_file(char *name, int *err);
int						ft_is_valid(char *str);
t_etri					ft_create_tetri(const char *str);
void					ft_get_size(const char *str, int *height, int *width);
void					ft_get_min_max(const char *str, t_point *min,
						t_point *max);
t_point					ft_get_pos(const char *str);
t_point					*ft_get_blocs(const char *str);

#endif
