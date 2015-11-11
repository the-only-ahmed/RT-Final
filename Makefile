# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/29 23:02:01 by jyim              #+#    #+#              #
#    Updated: 2015/10/29 23:02:02 by jyim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT

SRC = main.c parser.c ft_atof.c list_obj.c fill.c vector.c mlx.c
MLX = -I /usr/X11/include -L/usr/X11/lib -lmlx -framework OpenGl -framework AppKit
OBJ = $(SRC:.c=.o)

FLAGS = -g3 -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -I libft/ -L libft -lft $(SRC) $(MLX) -o $(NAME)

clean:
	@/bin/rm $(OBJ)
	@make -C libft/ clean

fclean:
	@/bin/rm -f $(OBJ)
	/bin/rm -f $(NAME)
re:fclean  all
