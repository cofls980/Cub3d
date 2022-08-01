#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../minilibx-linux/mlx.h" //need to modify

# define WIN_WIDTH 640//1280
# define WIN_HEIGHT 480//720

# define KEY_ESC		65307//53 need to modify
# define KEY_W			119//13 need to modify
# define KEY_A			97//0 need to modify
# define KEY_S			115//1 need to modify
# define KEY_D			100//2 need to modify
# define LEFT           65361// need to modify
# define RIGHT          65363// need to modify

# define KeyPress_X_EVENT 02
# define KeyRelease_X_EVENT 03
# define ButtonPress_X_EVENT 04
# define ButtonRelease_X_EVENT 05
# define KeyExit_X_EVENT 17

# define KeyPress_X_MASK 1L<<0
# define LeaveWindowMask 1L<<5

typedef struct s_mlx {
    //t_texture txt;
    //t_player ply;
    void *mlx_ptr; //mlx를 사용하기 위한 변수
    void *win_ptr; //윈도우를 띄우도록 하는 함수를 받는 변수
    //int win_width;
    //int win_height;
    //int map_width;
    //int map_height;
    //int count;
    //int collect_cnt;
    char **map;
} t_mlx;

#endif