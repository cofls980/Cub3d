NAME= cub3d
SRC = src/main_txt.c# main_floor_ceiling main_fc main_txt
OBJ = $(SRC:%.c=%.o)

MLX_DIR = ./minilibx-linux
LFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd
#MLX_DIR = ./minilibx-linux
#LFLAGS = -lXext -lX11 -lm -lz#-lbsd -lmlx lXext -lX11
#$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = ./includes

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

%.o: %.c
	$(CC) -I$(MLX_DIR) -I$(HEADER) -c -o $@ $<

#$(NAME): $(OBJ)
#	$(CC) $(OBJ) -L$(MLX_DIR) -L/usr/lib -I$(MLX_DIR) $(LFLAGS) -o $(NAME)
# $(CFLAGS)
#%.o: %.c
#	$(CC) -I/usr/include -I$(MLX_DIR) -I$(HEADER) -O3 -c -o $@ $<
# $(CFLAGS)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(NAME) $^

.PHONY: all clean fclean re bonus

#https://github.com/l-yohai/cub3d/blob/master/mlx_example/01_untextured_raycast.c
#https://github.com/365kim/raycasting_tutorial/blob/master/3_untextured_raycaster.md