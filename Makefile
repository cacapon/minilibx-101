# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 13:48:47 by ttsubo            #+#    #+#              #
#    Updated: 2025/02/06 14:16:28 by ttsubo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc -Wall -Wextra -Werror -Imlx
FLAGS	= -Lmlx -lmlx -lX11 -lXext

NAME01	= 01-show-window

all: $(NAME01)/$(NAME01).out

init: mlx-make

$(NAME01)/$(NAME01).out:
	$(CC) $(NAME01)/main.c $(FLAGS) -o $@

mlx-make: sub-update
	@echo "mlx make"
	@$(MAKE) -C mlx
	@echo "mlx make done"

sub-update:
	@echo "init submodule"
	@git submodule update --init
	@echo "init submodule done."

fclean:
	rm -rf 0*/*.out

re: fclean all

.PHONY: all init fclean re mlx-make sub-update