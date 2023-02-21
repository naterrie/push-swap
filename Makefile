# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 13:42:54 by naterrie          #+#    #+#              #
#    Updated: 2023/02/21 13:42:56 by naterrie         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #



NAME =	push_swap
CFLAGS = -Wall -Werror -Wextra
HEADERS = push_swap.h.h
OBJS =	$(SRCS:.c=.o)

SRCS =	src/atoi.c \
		src/SwapPush.c \
		src/instructions/push.c \
		src/instructions/swap.c \

all: $(NAME)
$(NAME): $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS)

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) -c -I $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
