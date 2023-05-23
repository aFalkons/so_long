# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 14:02:59 by afalconi          #+#    #+#              #
#    Updated: 2023/05/23 03:28:48 by afalconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long

SRCS	=	main.c \
			maker.c \
			gnl/get_next_line.c \
			gnl/get_next_line_utils.c \
			utils.c \
			setthings.c \
			movements.c \
			enemies.c

FLAGS	= -Wall -Wextra -Werror
CC		= gcc
RM		= rm -f
OBJ		= $(SRCS:.c=.o)
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c -g $< -o $@
$(NAME): $(OBJ)
	@make -C ./mlx
	# @cp ./mlx/libmlx.dylib
	$(CC)  $(OBJ) -L ./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)
clean:
	@make -C ./mlx clean
	$(RM) $(OBJ)
fclean: clean
	rm -rf libmlx.dylib
	$(RM) $(NAME)
re: fclean all
