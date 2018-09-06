# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apetrech <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/21 18:30:37 by apetrech          #+#    #+#              #
#    Updated: 2018/08/21 18:30:56 by apetrech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = fdf

FLAGS = -Wall -Wextra -Werror -g

LIBFT = libft

MLX = minilibx_macos

LIB = libft.a

SRCS = main.c \
		information.c \
		drawing.c \
		keys.c \
		helpers.c \

LIBFLAGS = -L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework Appkit

RED		=	\033[0;31m
YELL	=	\033[0;33m
PUR		=	\033[0;35m

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@echo "$(RED)compiling $@...$(PUR)"
	make -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(FLAGS) -c $(SRCS) -I $(LIBFT) -I $(MLX)
	$(CC) -o $(NAME) $(OBJS) $(LIBFLAGS) 

clean:
	@echo "$(YELL)deleting $@...$(PUR)"
	rm -f $(OBJS)
	make clean -C $(LIBFT)
	make clean -C $(MLX)

fclean: clean
	@echo "$(YELL)deleting $@...$(PUR)"
	rm -f $(NAME)
	rm -f $(LIBFT)/$(LIB)
	rm -f $(MLX)/libmlx.a

re: fclean all