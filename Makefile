# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msassaro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/21 12:40:25 by msassaro          #+#    #+#              #
#    Updated: 2016/03/21 12:40:59 by msassaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= wolf3d

LIB		= libft/libft.a mlx/libmlx.a
INCL	= -I libft/includes -I mlx/ -I ./
CC		= gcc
FLAGS	= -Wall -Wextra -Werror -O2
FRMK	= -framework OpenGL -framework AppKit

SRC		= \
		event.c\
		event2.c\
		ft_wolf_1_5.c\
		ft_wolf_6_8.c\
		init.c\
		main.c\
		map_recup.c\
		textures.c\
		ui.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) -c $(FLAGS) $(SRC) $(INCL)
	@$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIB) $(FRMK)

%.oL %.c:
	@gcc $(FLAG) -o $@ -c $^

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean
