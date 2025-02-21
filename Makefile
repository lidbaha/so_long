SRCS = core/so_long.c \
	utils/init.c \
	utils/movement.c \
	utils/so_long_utils.c \
	utils/map/map_checking/map_checker.c \
	utils/map/map_creation/map_creator.c \
	utils/map/map_checking/map_checker_2.c \
	utils/map/map_creation/map_creator_2.c \
	utils/map/map_checking/map_checker_3.c \
	includes/get_next_line/get_next_line.c \
	includes/get_next_line/get_next_line_utils.c \

NAME = so_long
OBJS = $(SRCS:.c=.o)
MLX = includes/minilib/libmlx.a
MLXFLAGS = -Iincludes/minilib/ -Iminilibx-linux
PRINTF_DIR = includes/ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
LIBFT_DIR = includes/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(PRINTF_LIB) $(LIBFT_LIB) $(NAME)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS) $(MLX) $(PRINTF_LIB) $(LIBFT_LIB) -lX11 -lXext -lm

%.o: %.c
	$(CC) $(CFLAGS) $(MLXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all