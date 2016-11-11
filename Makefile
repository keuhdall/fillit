#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: lmarques <lmarques@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/10 23:15:25 by lmarques          #+#    #+#             *#
#*   Updated: 2016/11/11 01:28:36 by lmarques         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = fillit

SRC = fillit.c \
		checker.c \
		reader.c \
		solver.c \
		tetri.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		make -C libft
		gcc -Wall -Werror -Wextra -c $(SRC)
		gcc -Wall -Werror -Wextra $(OBJ) -o $(NAME) -L./libft -lft

clean:
		make -C libft clean
		rm -rf $(OBJ)

fclean: clean
		make -C libft fclean
		rm -rf $(NAME)

re : fclean all
