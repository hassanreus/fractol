# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hseffian <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 12:02:10 by hseffian          #+#    #+#              #
#    Updated: 2019/10/31 12:02:15 by hseffian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIBFT_PATH = ./get_next_line/libft/
LIB = -lmlx -framework OpenGL -framework  AppKit
SRC = main.c\
		
OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror
all: $(NAME)
$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@gcc $(OBJ) $(LIB) $(LIBFT_PATH)/libft.a -o $(NAME)
$(OBJ): %.o : %.c
	@gcc $(FLAGS) -c $< -o $@
clean:
	@make -C $(LIBFT_PATH) clean
	@rm -rf $(OBJ)
fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@rm -rf $(NAME)
re: fclean all