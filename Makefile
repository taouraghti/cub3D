# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 18:33:25 by aidrissi          #+#    #+#              #
#    Updated: 2020/02/03 18:34:49 by aidrissi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

SRCS = draw/draw.c get_next_line/get_next_line.c\
	   get_next_line/get_next_line_utils.c keys.c\
	   world_game/read_map.c sprite.c utils.c\
	   world_game/check_map.c main.c world_game/utils1.c\
	   init_player.c screen.c draw/draw_wall.c\
	   draw/draw_sprite.c initGame/init_mlx.c initGame/check_position.c\
	   world_game/read_map_utils.c ft_split.c

OBJ = draw/draw.o get_next_line/get_next_line.o\
	  get_next_line/get_next_line_utils.o keys.o\
	  world_game/read_map.o sprite.o utils.o\
	  world_game/check_map.o main.o world_game/utils1.o\
	  init_player.o screen.o draw/draw_wall.o\
	  draw/draw_sprite.o initGame/init_mlx.o initGame/check_position.o\
	  world_game/read_map_utils.o ft_split.o

CFLAGS = -Wall -Wextra -Werror

CC = gcc 

MLX_LIB = mlx/libmlx.a

MLX = -lmlx -framework OpenGL -framework AppKit -lz $(MLX_LIB)

all: $(NAME)

$(MLX_LIB):
	make -C mlx/

$(NAME): $(OBJ) $(MLX_LIB)
	@$(CC) -o $@ $(OBJ) $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME)

clean:
	@make clean -C mlx/
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) 

re: fclean all
