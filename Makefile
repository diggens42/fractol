NAME = fractol

CC = cc
CFLAGS = -Werror -Wextra -Wall
LIBFT = ./libft/libft.a

MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit
MLXINCLUDE = MLX42/build/libmlx42.a -Iinclude -lglfw

SRCS = main.c errorhandler.c init.c utils.c events.c

OBJS = $(SRCS:%.c=%.o)


all: $(NAME)

$(LIBFT):
		$(MAKE) -C ./libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLXFLAGS) $(MLXINCLUDE) $(LIBFT)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
