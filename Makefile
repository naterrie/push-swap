# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 13:42:54 by naterrie          #+#    #+#              #
#    Updated: 2023/03/13 14:19:03 by naterrie         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap
CFLAGS = -Wall -Werror -Wextra
HEADERS = swap_push.h
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
		swap_push.c \
		set_arg.c \
		set_args.c \
		split.c \
		instructions.c \
		checkminus.c

all: $(NAME)
	echo "$(GREEN)✅ Push swap compilated !"

$(NAME): $(DIR_OBJS) $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(HEADERS)
	echo "$(GREEN)⏳ Making $(NAME)"
	printf "$(BLEU) ⮡ Making $(RESET)$@$(RED)"
	gcc $(CFLAGS) -c $< -o $@ -I.
	sleep 0.05
	printf "$(ERASE)"

$(DIR_OBJS):
	mkdir -p $@

ok: re clean

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
