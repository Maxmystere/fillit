# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: magrab <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 19:13:31 by magrab            #+#    #+#              #
#    Updated: 2019/09/25 17:57:56 by magrab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

NAME		=	fillit

SRCS		=	./read_file.c \
				./solve_fillit.c

OBJS		=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C libft/
	$(CC) -Wall -Wextra -Werror -o $(NAME) $(OBJS) libft/libft.a

clean:
	$(MAKE) -C libft/ clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
