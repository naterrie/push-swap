# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenumy <adenumy@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 13:42:54 by naterrie          #+#    #+#              #
#    Updated: 2023/03/07 21:23:00 by adenumy          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap
CFLAGS = -Wall -Werror -Wextra
HEADERS = SwapPush.h
OBJS =	$(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))
DIR_SRCS := src
DIR_OBJS := .objs

BLEU := \033[36m
PURPLE := \033[35m
GREEN := \033[32m
RED := \033[31m
RESET := \033[0m
ERASE := \033[2K\033[1A\r

SRCS =	sort.c \
		SwapPush.c \
		setSwaparg.c \
		Pushargs.c \
		split.c \
		instructions.c \
		checkminus.c \
		test.c

all: $(NAME)
	echo "$(GREEN)✅ Push swap compilated !"

$(NAME): $(DIR_OBJS) $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(HEADERS)
	echo "$(GREEN)⏳ Making $(NAME)"
	printf "$(BLEU) ⮡ Making $(RESET)$@$(RED)"
	gcc $(CFLAGS) -c $< -o $@ -I.
	sleep 0.1
	printf "$(ERASE)"

$(DIR_OBJS):
	mkdir -p $@

ok: all clean

clean:
	echo "$(PURPLE)🧹Removing .o files !"
	rm -rf $(DIR_OBJS)

fclean: clean
	echo "$(PURPLE)🧹Removing $(NAME:.a=) !"
	rm -f $(NAME)

re: fclean $(NAME)
	echo "$(GREEN)✅ Push swap recompilated !"

.PHONY: clean fclean re all

.SILENT:
