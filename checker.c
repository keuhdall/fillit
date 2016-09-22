/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 23:22:08 by lmarques          #+#    #+#             */
/*   Updated: 2016/09/23 01:17:25 by lmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_blocks(char *str)
{
	int	count;
	int	count_block;

	count = 0;
	count_block = 0;
	while (str[count])
	{
		if (str[count] == '#')
			count_block++;
		count++;
	}
	return (count_block);
}

int		ft_is_valid(char *str)
{
	int	count;
	int	count_block;

	count = 0;
	count_block = 0;
	while (str[count])
	{
		if (str[count] != '.' && str[count] != '\n' && str[count] != '#')
			return (0);
		if (str[count] == '#')
		{
			if (str[count - 1] && str[count - 1] == '#')
				count_block++;
			if (str[count + 1] && str[count + 1] == '#')
				count_block++;
			if (str[count - 5] && str[count - 5] == '#')
				count_block++;
			if (str[count + 5] && str[count + 5] == '#')
				count_block++;
		}
		count++;
	}
	if ((count_block == 6 || count_block == 8) && ft_count_blocks(str) == 4)
		return (1);
	return (0);
}
