# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nibernar <nibernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 12:02:24 by nibernar          #+#    #+#              #
#    Updated: 2023/09/23 18:29:08 by nibernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################
#		MAKEFILE		#
#########################

NAME		=	cub3d

#########################
#	 LIBFT FOLDERS		#
#########################

LIBFT_PATH	=	./libft/
LIBFT_FILE	=	libft.a
LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

#########################
#	FOLDERS AND NAMES	#
#########################

SRC_DIR		=	./src/

SRCS		=	cub.c\
				parsing.c\
				
SRC			=	$(addprefix $(SRC_DIR),$(SRCS))

OBJ			=	$(SRC:.c=.o)

#########################
# 	COMPILER OPTIONS	#
#########################

CC			=	cc
FLAG		=	-Wall -Wextra -Werror -g3


#########################
#	 MLX FOLDERS		#
#########################

MLX_FILE	=	libmlx.a
MLX_FLAG	=	-L ./mlx -lXext -lX11 -lm -lbsd
MLX_PATH	=	./MLX_extention/Lib_MLX/
#MLX_PATH	=	./mlx/
MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)


INC_DIR		=	./include/


#########################
# 		RULES			#
#########################

all: lib mlx $(NAME)

%.o: %.c ${INC_DIR} -I cub3d.h
	$(CC) $(FLAG) -Imlx ${LIBFT_LIB} -c $< -o $@

mlx:
	@echo "COMPILING MLX..."
	@make -sC $(MLX_PATH)
	@echo "MLX_lib created"

$(NAME): $(OBJ)
	@echo "COMPILING CUB3D...\n"
	$(CC) $(OBJ) -Llibft -lft ${MLX_FLAG} -o $(NAME)
	@echo "CUB3D created\n"

#########################
# 	CLEAN COMMANDS		#
#########################

force :

lib:
	@echo "COMPILING $(LIBFT_PATH)"
	@make -C $(LIBFT_PATH)
	@echo "LIBFT created"

clean :
	@echo "Deleting Obj file in $(MLX_PATH)..."
	@make clean -sC $(MLX_PATH)
	@echo "Deleting Obj file in $(LIBFT_PATH)..."
	@make clean -sC $(LIBFT_PATH)
	@echo "Done"
	@echo "Deleting cub3d object..."
	@rm -f $(OBJ)
	@echo "Done"

fclean: clean
	@echo "Deleting cub3d executable..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo "Done"

re: fclean all

.PHONY: all clean fclean re lib mlx
