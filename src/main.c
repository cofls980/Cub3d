#include "../include/cub3d.h"

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void init(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
	cub->posX = 22;
	cub->posY = 12;
	cub->dirX = -1;
	cub->dirY = 0;
	cub->planeX = 0;
	cub->planeY = 0.66;
	cub->rotSpeed = 0.05;
	cub->moveSpeed = 0.05;
}

int main_loop(t_cub *cub)
{
	raycasting(cub);

	return (0);
}

int main(int argc, char **argv)
{
	t_cub cub;
	init(&cub);

	//raycasting(&cub);
	mlx_loop_hook(cub.mlx, &main_loop, &cub);
	mlx_hook(cub.win, KeyPress_X_EVENT, KeyPress_X_MASK, &key_press, &cub);
	mlx_hook(cub.win, KeyExit_X_EVENT, LeaveWindowMask, &quit_press, &cub);
	mlx_loop(cub.mlx);  
  /*double time = 0; //time of current frame
  double oldTime = 0; //time of previous frame
  //|time - oldTime| =  특정 키를 눌렀을 때 이동해야하는 정도를 결정하는데 사용(FPS 계산?)
  //screen(screenWidth, screenHeight, 0, "Raycaster");//해상도 결정
  while(!done())//전체 프레임과 매번 입력을 읽는 루프
  {
    //timing for input and FPS counter
    oldTime = time;
    time = getTicks();
    double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    print(1.0 / frameTime); //FPS counter
    redraw();
    cls();

    //speed modifiers
    double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
    readKeys();
    //rotate to the right
  }*/
  return (0);
}

int	quit_press(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	exit(0);
	return (0);
}

int key_press(int keycode, t_cub *cub)
{
	if (keycode == KEY_W)
	{
		if(worldMap[(int)(cub->posX + cub->dirX * cub->moveSpeed)][(int)cub->posY] == 0)
			cub->posX += cub->dirX * cub->moveSpeed;
		if(worldMap[(int)(cub->posX)][(int)(cub->posY + cub->dirY * cub->moveSpeed)] == 0)
			cub->posY += cub->dirY * cub->moveSpeed;
	}
	else if (keycode == KEY_S)
	{
		if(worldMap[(int)(cub->posX - cub->dirX * cub->moveSpeed)][(int)(cub->posY)] == 0)
			cub->posX -= cub->dirX * cub->moveSpeed;
		if(worldMap[(int)(cub->posX)][(int)(cub->posY - cub->dirY * cub->moveSpeed)] == 0)
			cub->posY -= cub->dirY * cub->moveSpeed;
	}
	else if (keycode == KEY_D)//오른쪽 회전
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = cub->dirX;
		cub->dirX = cub->dirX * cos(-cub->rotSpeed) - cub->dirY * sin(-cub->rotSpeed);
		cub->dirY = oldDirX * sin(-cub->rotSpeed) + cub->dirY * cos(-cub->rotSpeed);
		double oldPlaneX = cub->planeX;
		cub->planeX = cub->planeX * cos(-cub->rotSpeed) - cub->planeY * sin(-cub->rotSpeed);
		cub->planeY = oldPlaneX * sin(-cub->rotSpeed) + cub->planeY * cos(-cub->rotSpeed);
	}
	else if (keycode == KEY_A)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = cub->dirX;
		cub->dirX = cub->dirX * cos(cub->rotSpeed) - cub->dirY * sin(cub->rotSpeed);
		cub->dirY = oldDirX * sin(cub->rotSpeed) + cub->dirY * cos(cub->rotSpeed);
		double oldPlaneX = cub->planeX;
		cub->planeX = cub->planeX * cos(cub->rotSpeed) - cub->planeY * sin(cub->rotSpeed);
		cub->planeY = oldPlaneX * sin(cub->rotSpeed) + cub->planeY * cos(cub->rotSpeed);
	}
	else if (keycode == KEY_ESC)
		quit_press(cub);
	return (0);
}

void	verLine(t_cub *cub, int x, int y1, int y2, int color)
{
	int	y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(cub->mlx, cub->win, x, y, color);
		y++;
	}
}

void raycasting(t_cub *cub)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		double cameraX = 2 * x / (double)WIN_WIDTH - 1; //for문의 x값(화면의 수직선)이 위치가 카메라 평면에 차지하는 x좌표//x-coordinate in camera space 카메라 평면의 x 좌표
    	double rayDirX = cub->dirX + cub->planeX * cameraX; // 광선의 방향 벡터, 플레이어에서 광선이 평면 벡터의 어느 지점까지의 방향 벡터
    	double rayDirY = cub->dirY + cub->planeY * cameraX;
		//which box of the map we're in
      	int mapX = (int)cub->posX;//현재 광선의 위치, 광선이 있는 한 칸(square)
      	int mapY = (int)cub->posY;

		//length of ray from current position to next x or y-side
		double sideDistX; // 현재 위치에서 광선이 만나는 가장 가까운 x면
		double sideDistY; // 현재 위치에서 광선이 만나는 가장 가까운 y면

		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist; // 광선의 이동거리를 계산하는데 사용된다.

		int stepX; // 어느 뱡향으로 가야할지
		int stepY;

		int hit = 0; //벽과 만났는지was there a wall hit?
		int side; //벽의 어느 면과 만났는지was a NS or a EW wall hit?

		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (cub->posX - mapX) * deltaDistX;
		}
		else // rayDirX 또는 rayDirY의 값이 0이라면, stepX 또는 stepY는 사용되지 않으므로 어떤 값ㅇ르 갖든 상관없다.
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - cub->posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (cub->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - cub->posY) * deltaDistY;
		}

		while(hit == 0)
		{
		//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(worldMap[mapY][mapX] > 0) hit = 1;
		}

		if(side == 0)
			perpWallDist = (mapX - cub->posX + (1 - stepX) / 2) / rayDirX;//(sideDistX - deltaDistX); // EW
      	else
			perpWallDist = (mapY - cub->posY + (1 - stepY) / 2) / rayDirY;//(sideDistY - deltaDistY); // NS

		int lineHeight = (int)(WIN_HEIGHT / perpWallDist);//Height자리는 바꿀 수 있다. 일정한 벽의 높이, 너비 및 깊이를 가진 박스처럼 보이게 해주고, 값이 클수록 높이가 높은 박스를 만들어준다.

		//calculate lowest and highest pixel to fill in current stripe
		// 벽의 중심은 화면의 중심에 있어야하고, 이 중심점이 화면 범위 아래에 놓여있다면 0으로, 화면 범위 밖에 놓여있다면 h - 1로 덮어씌운다.
		int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if(drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;

		int color;
		if (worldMap[mapY][mapX] == 1)
			color = 0xFF0000;
		else if (worldMap[mapY][mapX] == 2)
			color = 0x00FF00;
		else if (worldMap[mapY][mapX] == 3)
			color = 0x0000FF;
		else if (worldMap[mapY][mapX] == 4)
			color = 0xFFFFFF;
		else
			color = 0xFFFF00;

		if(side == 1)
			color = color / 2;

		verLine(cub, x, drawStart, drawEnd, color);

		x++;
	}
}