/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 23:22:08 by lmarques          #+#    #+#             */
/*   Updated: 2016/11/08 21:28:25 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_blocs(const char *str)
{
	int	count;
	int	count_blocs;

	count = 0;
	count_blocs = 0;
	while (count < 20)
	{
		if (str[count] == '#')
			count_blocs++;
		count++;
	}
	return (count_blocs);
}

int		ft_check_endline(const char *str)
{
	int	count;

	count = 0;
	while (count < 20)
	{
		if (str[count] == '\n')
		{
			if (count != 4 && count != 9 && count != 14 && count != 19)
				return (0);
		}
		count++;
	}
	return (1);
}

int		ft_is_valid(char *str)
{
	int	count;
	int	count_blocs;

	count = 0;
	count_blocs = 0;
	while (count < 20)
	{
		if (str[count] != '.' && str[count] != '\n' && str[count] != '#')
			return (0);
		if (str[count] == '#')
		{
			if ((count + 1) < 20 && str[count + 1] == '#')
				count_blocs++;
			if ((count - 1) >= 0 && str[count - 1] == '#')
				count_blocs++;
			if ((count + 5) < 20 && str[count + 5] == '#')
				count_blocs++;
			if ((count - 5) >= 0 && str[count - 5] == '#')
				count_blocs++;
		}
		count++;
	}
	if ((count_blocs == 6 || count_blocs == 8) && ft_count_blocs(str) == 4 && 
		ft_check_endline(str))
		return (1);
	return (0);
}
