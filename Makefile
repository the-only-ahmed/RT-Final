# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/07 21:28:19 by ael-kadh          #+#    #+#              #
#    Updated: 2014/03/27 21:02:24 by ael-kadh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	rt
SRC			=	main.c vectors.c raytracer.c raytray.c trace.c\
				geo.c spaces.c sphere.c spot.c intersection.c\
				object_parsing.c plan_parsing.c cone_inter.c object_normal.c\
				parse.c parse_verif.c parse_verif_2.c parse_2.c define.c

HEAD		=	ray.h lists.h
OBJ			=	$(SRC:.c=.o)
FLAGS		=	-Wall -Wextra -Werror -g3

# COLORS
C_NO		=	"\033[00m"
C_OK		=	"\033[35m"
C_GOOD		=	"\033[32m"
C_ERROR		=	"\033[31m"
C_WARN		=	"\033[33m"

# DBG MESSAGE
SUCCESS		=	$(C_GOOD)SUCCESS$(C_NO)
OK			=	$(C_OK)OK$(C_NO)

all : $(NAME)

$(NAME) :
	@make -C libft
	@gcc $(FLAGS) -I libft/includes -I /usr/X11/include -I /usr/include\
					-I libft/printf/includes -c $(SRC)
	@gcc $(OBJ) -L libft -lft -L/usr/X11/lib -lmlx -lXext -lX11\
					libft/printf/libftprintf.a -o $(NAME)
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

clean :
	@make -C libft clean
	@rm -f $(OBJ)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)


fclean : clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "Delete" [ $(NAME) ] $(OK)

re : fclean all

.PHONY: all clean fclean re
