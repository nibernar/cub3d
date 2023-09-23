# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 15:01:55 by nibernar          #+#    #+#              #
#    Updated: 2023/08/07 22:48:46 by nicolasbern      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################
#		MAKEFILE		#
#########################

NAME		= 	libft.a

INC_DIR		= 	include/

INC			= 	libft.h

SRC_DIR		= 	src/


#########################
#	FOLDERS AND NAMES	#
#########################

SRC			= 	checks/ft_isalpha.c \
 			   	checks/ft_isdigit.c \
 			   	checks/ft_isalnum.c \
 			   	checks/ft_isascii.c \
 			   	checks/ft_isprint.c \
 			   	checks/ft_isspace.c \
 			   	str/ft_toupper.c \
 			   	str/ft_tolower.c \
 			   	str/ft_atoi.c \
 			   	str/ft_strdup.c \
 			   	str/ft_strchr.c \
 			   	str/ft_strrchr.c \
 			   	str/ft_strlen.c \
 			   	str/ft_strlcpy.c \
 			   	str/ft_strlcat.c \
 			   	str/ft_strncmp.c \
 			   	str/ft_strnstr.c \
 			   	str/ft_substr.c \
 			   	str/ft_strjoin.c \
 			   	str/ft_strtrim.c \
 			   	str/ft_split.c \
 			   	str/ft_itoa.c \
 			   	str/ft_strmapi.c \
 			   	str/ft_striteri.c \
 			   	memory/ft_calloc.c \
 			   	memory/ft_bzero.c \
 			   	memory/ft_memset.c \
 			   	memory/ft_memcpy.c \
 			   	memory/ft_memmove.c \
 			   	memory/ft_memchr.c \
 			   	memory/ft_memcmp.c \
				memory/ft_free.c \
 			   	write_fd/ft_putchar_fd.c \
 			   	write_fd/ft_putstr_fd.c \
 			   	write_fd/ft_putendl_fd.c \
 			   	write_fd/ft_putnbr_fd.c \
				lst/ft_lstnew.c \
 				lst/ft_lstsize.c \
 			   	lst/ft_lstclear.c \
 			   	lst/ft_lstadd_back.c \
 			   	lst/ft_lstadd_front.c \
 			   	lst/ft_lstlast.c \
 			   	lst/ft_lstdelone.c \
 			   	lst/ft_lstiter.c \
 			   	lst/ft_lstmap.c\
				printf/ft_printf.c \
				printf/ft_print_pointer.c \
				printf/ft_print_unsigned_int_fd.c \
				printf/ft_printnbr.c \
				printf/ft_printnbr_base.c \
				printf/ft_printstr.c \
				get_next_line/ft_get_next_line.c\
				get_next_line/get_next_line_util.c\

OBJ_DIR		=	build/
OBJ			=	$(SRC:%.c=$(OBJ_DIR)%.o)


#########################
# 	COMPILER OPTIONS	#
#########################

CC			=	gcc
CC_FLAGS	=	-Wextra -Werror -Wall


#########################
# 		RULES			#
#########################

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "> libft Done!\n"

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)$(INC)
	@mkdir -p $(@D)
	@echo "compiling: $<$(_END)"
	@$(CC) $(CC_FLAGS) -I $(INC_DIR) -c $< -o $@


#########################
# 	CLEAN COMMANDS		#
#########################

clean:
	@echo "remove $(OBJ_DIR)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "remove $(NAME)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
