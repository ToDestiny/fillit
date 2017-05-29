# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llorgere <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/15 12:55:31 by llorgere          #+#    #+#              #
#    Updated: 2017/05/23 11:13:19 by llorgere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fillit
SRC = ft_tetra_nb_char.c \
	  ft_check_tetra.c \
	  ft_tetra_valid.c \
	  main.c
CC = gcc
HEADER = ./libft/libft.a
CFLAGS = -Wall -Wextra -Werror
.PHONY : all clean fclean re

all : $(NAME)

$(NAME) :
	@make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(HEADER)

clean :
	@make -C libft clean
	@/bin/rm -rf $(OBJ)

fclean : clean
	@make -C libft fclean
	@/bin/rm -rf $(NAME)

re : fclean all
