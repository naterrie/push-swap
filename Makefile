# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 13:42:54 by naterrie          #+#    #+#              #
#    Updated: 2023/03/03 16:35:27 by naterrie         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap
CFLAGS = -Wall -Werror -Wextra
HEADERS = SwapPush.h
OBJS =	$(SRCS:.c=.o)

SRCS =	src/sort.c \
		src/SwapPush.c \
		src/setSwaparg.c \
		src/setSwapPushargs.c \
		src/split.c \
		src/instructions.c \
		src/checkminus.c \

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
