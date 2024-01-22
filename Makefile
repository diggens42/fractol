NAME = fractol

CC = cc
CFLAGS = -Werror -Wextra -Wall
LIBFT = ./libft/libft.a

MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit
MLXLIB=MLX42/build/libmlx42.a
MLXINCLUDE = -Iinclude -lglfw
HEADERS=fractol.h

SRCS = main.c errorhandler.c init.c utils.c events.c

OBJS = $(SRCS:%.c=%.o)

SAN_LDFLAGS = -L../LeakSanitizer -llsan -lc++ -Wno-gnu-include-next -I ../LeakSanitize

all: $(NAME)

%.o: %.c $(HEADERS) Makefile
	$(CC) -c $< -o $@

$(LIBFT):
		$(MAKE) -C ./libft

$(MLXLIB):
	(cd MLX42 && cmake -B build && cmake --build build -j4)

$(NAME): $(LIBFT) $(MLXLIB) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^ $(MLXFLAGS) $(SAN_LDFLAGS) $(MLXINCLUDE)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
