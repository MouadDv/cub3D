# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/30 12:50:51 by milmi             #+#    #+#              #
#    Updated: 2021/01/26 08:20:24 by milmi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRCS =  files/cub3d_utils.c \
		files/cubdata.c \
		files/cubdata_norm1.c \
		files/cubdata_norm2.c \
		files/cubdata_norm3.c \
		files/cubdata_norm4.c \
		files/cubdata_norm5.c \
		files/cubdata_norm6.c \
		files/dotcub_utils.c \
		files/init.c \
		files/key.c \
		files/key_utils.c \
		files/ray.c \
		files/ray_norm.c \
		files/ray_utils.c \
		files/save.c \
		files/sprite.c \
		files/sprite_norm.c \
		files/sprite_utils.c \
		files/write_bmp.c \
		includes/GNL/get_next_line.c \
		includes/GNL/get_next_line_utils.c \
		cub3d.c

FLAGS=  -Wall -Wextra -Werror -g
MFLAGS = -I. -lmlx $(MLX) -framework OpenGL -framework AppKit
MLX = libmlx.dylib
rm = rm -f
CC = gcc

all : $(NAME)

$(NAME) : $(MLX)
	@cp ./includes/minilibx/libmlx.dylib .
	@$(CC) $(MFLAGS) $(FLAGS) $(SRCS) -o $(NAME)
	
$(MLX) :
	@$(MAKE) -C ./includes/minilibx
	
clean :
	@$(rm) $(NAME)
	@$(rm) $(MLX)
	@$(MAKE) -C ./includes/minilibx clean
	
fclean : clean

re: fclean all
