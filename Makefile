# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlucas-s <jlucas-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 23:34:47 by jlucas-s          #+#    #+#              #
#    Updated: 2022/09/26 20:29:11 by jlucas-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Werror -Wall -Wextra -lmlx -lXext -lX11

GREEN				= \033[1;32m
NOCOLOR				= \033[0m

LIBFTPATH = ./lib
LIBFT = ./lib/libft.a

SRCS = src/main.c \
	   src/validations.c \
	   src/init.c \
	   src/destroy.c \
	   src/draw.c \
	   src/testes.c \

all: ${NAME}

${NAME}: ${OBJS}
	make -C ${LIBFTPATH}
	cc $(SRCS) $(LIBFT) $(FLAGS) -o $(NAME)
	@ echo "${GREEN}-=-FDF SUCCESSFUL COMPILED-=-${NOCOLOR}"
	
clean:
	make fclean -C ${LIBFTPATH}

rmv:
	rm -f $(NAME)

fclean: rmv clean

re: fclean all

refast: rmv all

.PHONY: all clean fclean re