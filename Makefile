# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/27 16:44:56 by mvelluet          #+#    #+#              #
#    Updated: 2017/05/04 22:45:19 by mvelluet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS =  ft_controleur.c \
		ft_init.c \
		ft_julia.c \
		ft_key_event.c \
		ft_mandelbrot.c \
		ft_mike.c \
		ft_mouse_event.c \
		ft_put_pixel_color.c \
		main.c

CFLAGS = -Wall -Werror -Wextra

INCLUDE = fractol.h

OBJ = $(SRCS:.c=.o)

CC = gcc

MINILIB = minilibx_macos/libmlx.a

all: $(NAME) $(INCLUDE)

$(NAME): $(MINILIB) $(OBJ)
	make -C libft
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(MINILIB) -framework OpenGL -framework Appkit libft/libft.a
	echo "Fractol done" $@

$(MINILIB):
	make -C minilibx_macos

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all