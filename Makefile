# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magrab <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 19:13:31 by magrab            #+#    #+#              #
#    Updated: 2019/01/09 15:07:41 by tferrieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLG-C		=	-c -Wall -Wextra -Werror

FLG-O		=	-Wall -Wextra -Werror -o

CC			=	gcc

NAME		=	fillit

SRC-C		=	./read_file.c \
				./solve_fillit.c

SRC-O		=	$(SRC-C:.c=.o)

all: $(NAME)

$(NAME):
	$(MAKE) -C libft/
	$(CC) $(FLG-C) $(SRC-C)
	$(CC) $(FLG-O) $(NAME) $(SRC-O) libft/libft.a

clean:
	$(MAKE) -C libft/ clean
	rm -f $(SRC-O)

fclean: clean
	$(MAKE) -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
