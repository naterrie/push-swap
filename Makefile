# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 13:42:54 by naterrie          #+#    #+#              #
#    Updated: 2023/02/21 17:25:30 by naterrie         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap
CFLAGS = -Wall -Werror -Wextra
HEADERS = SwapPush.h
OBJS =	$(SRCS:.c=.o)

SRCS =	src/atoi.c \
		src/SwapPush.c \
		src/instructions/push.c \
		src/instructions/swap.c \
		src/instructions/rotate.c \
		src/instructions/reverserotate.c \

all: $(NAME)
$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c $< -o $@ -I.

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
