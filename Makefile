NAME =	push_swap
CFLAGS = -Wall -Werror -Wextra
HEADERS = push_swap.h.h
OBJS =	$(SRCS:.c=.o)

SRCS =	src/atoi.c \
		src/main.c \
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
