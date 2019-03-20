#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/23 15:21:44 by ddehtyar          #+#    #+#              #
#    Updated: 2018/07/23 17:04:55 by ddehtyar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	:=		wolf3d

FLAGS	:=		-Wall -Werror -Wextra -O2

SRC		:=		main.c check_eror.c image.c reading.c texture.c hook.c raycasting.c draw.c hook_help.c

HEAD	:=		wolf3d.h

OBJ		:=		$(SRC:.c=.o)

LIB		:=		./libft/libft.a

MLX		:=		-lmlx -framework OpenGL -framework AppKit

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C libft
			@gcc $(FLAGS) -I $(HEAD) -c $(SRC)
			@gcc $(FLAGS) $(LIB) $(MLX) -o $(NAME) $(OBJ)
			@echo "\033[95mall is ready, baby\033[0m"
			@say "all is ready baby"

$(OBJ):		%.o: %.c
			@gcc $(FLAGS) -I $(HEAD) -c $< -o $@

clean:
			@make -C libft clean
			@/bin/rm -f $(OBJ)
			@echo "\033[91mObject files have been deleted\033[0m"

fclean:		clean
			@make -C libft fclean
			@/bin/rm -f $(NAME)
			@echo "\033[91mExecutables have been deleted\033[0m"

re:			fclean all

.PHONY:all clean fclean re