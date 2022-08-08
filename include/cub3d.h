#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "../minilibx-linux/mlx.h" //need to modify

# define WIN_WIDTH 640//1280
# define WIN_HEIGHT 480//720
# define mapWidth 24
# define mapHeight 24

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

#define texWidth 64
#define texHeight 64

typedef struct	s_img
{
	void	*img;//스크린에 입힐 새로운 이미지 공간을 받음
	int		*data;//스크린에 이미지를 입힐 떄 필요한 주소

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_cub {
    //t_texture txt;
    //t_player ply;
    void *mlx; //mlx를 사용하기 위한 변수
    void *win; //윈도우를 띄우도록 하는 함수를 받는 변수
    double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
    double moveSpeed;
    double rotSpeed;

    t_img img;// 스크린에 이미지를 표현하기 위해 필요한 구조체
    int buf[WIN_HEIGHT][WIN_WIDTH]; // 스크린 각 픽셀에 들어가야할 이미지 색깔
    int **texture; // 각 텍스터를 읽은 데이터 저장
    //int win_width;
    //int win_height;
    //int map_width;
    //int map_height;
    //int count;
    //int collect_cnt;
    //char **map;
} t_cub;

int key_press(int keycode, t_cub *cub);
int	quit_press(t_cub *cub);
void raycasting(t_cub *cub);

#endif