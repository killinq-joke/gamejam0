CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c handlers.c init.c
OBJS = $(SRCS:c=o)
NAME = cacland

.c.o:
	$(CC) $(CFLAGS) $(SRCS) -Iminilibx -c

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJS)
	make -C minilibx
	$(CC) $(CFLAGS) $(OBJS) -I. -LminilibX -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all