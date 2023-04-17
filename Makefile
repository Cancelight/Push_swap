# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/20 15:51:38 by bkiziler          #+#    #+#              #
#    Updated: 2023/04/17 13:39:52 by bkiziler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./Sources/appended.c \
		./Sources/main.c \
		./Sources/operations.c \
		./Sources/operation2.c \
		./Sources/push_split.c \
		./Sources/Utils.c \
		./Sources/duplication.c

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
PRINTF = ./printf/libftprintf.a
LIBFT = ./libft/libft.a

all:	$(NAME)

$(NAME) : $(PRINTF) $(LIBFT) $(SRC)
		$(CC) $(CFLAGS) $(PRINTF) $(LIBFT) $(SRC) -o $(NAME)

$(PRINTF):
		@make -C ./printf

$(LIBFT):
		@make -C ./libft
		@make -C ./libft bonus

clean:
		@make -C ./printf clean
		@make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
		@make -C ./printf fclean
		@make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
