# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyim <jyim@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/29 23:02:01 by jyim              #+#    #+#              #
#    Updated: 2015/11/19 21:53:57 by ael-kadh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT
SRC = main.c parser.c ft_atof.c list_obj.c fill.c vector.c mlx.c ray.c ray2.c \
	  ray3.c ray4.c ft_render.c hit_cylinder.c inter_cone.c hit.c fill2.c \
	  vector2.c key_hook.c expose.c

MLX = -I /usr/X11/include -L/usr/X11/lib -lmlx -framework OpenGl -framework AppKit
OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror


all: build $(NAME) finish

build:
	@make -C libft

$(NAME): $(OBJ)
	@gcc $(OBJ) -L libft -lft $(MLX) -o $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c -I libft/includes $<

clean:
	@rm -f $(OBJ_S)
	@make -C libft/ clean

fclean: clean
	@rm -f ../$(NAME_Serv)
	@make -C libft/ fclean

re: fclean all

finish:
	@(echo "[\033[32m$(NAME_Serv)\033[00m]")

.PHONY: all build clean fclean re
