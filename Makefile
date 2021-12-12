NAME = cacland

OBJ = bin/img.o

BIN = bin
FLAGS = -Wall -Wextra -Werror -Ofast

OS = $$(uname -s)

ECHO = echo
RED = \033[31m
GRE = \033[32m
GRA = \033[37m
BLU = \033[34m
EOC = \033[0m

all: $(NAME)

run: all
	./$(NAME)

bin/%.o: %.c
	@$(ECHO) "$(BLU)● Compiling $^ 🔧$(EOC)"
	@mkdir -p $(BIN)
	@gcc $(FLAGS) -c -I/usr/local/include $^ -o $@

$(NAME): $(OBJ)
	@if [ $(OS) = 'Linux' ]; then \
		$(ECHO) "$(GRE)● Compiling to binary ⚙️  $(GRA)(Linux 🐧 mode)$(EOC)"; \
		gcc $(FLAGS) -L/usr/local/lib $(OBJ) -o $(NAME) -lm -lmlx -lXext -lX11 -lz; \
	else \
		$(ECHO) "$(GRE)● Compiling to binary ⚙️  $(GRA)(maxOS 🍎 mode)$(EOC)"; \
		gcc $(FLAGS) -l mlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME) -lm; \
	fi

clean:
	@$(ECHO) "$(RED)● Removing /$(BIN) 📁$(EOC)"
	@rm -rf $(BIN)

fclean: clean
	@$(ECHO) "$(RED)● Removing binary ⚙️ $(EOC)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all run clean fclean re
