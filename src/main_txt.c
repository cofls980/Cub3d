#include "../include/cub3d.h"

/*int worldMap[mapWidth][mapHeight]=
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
};*/

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void init(t_cub *cub) // 구조체 초기화
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

void	draw(t_cub *info)
{
	for (int y = 0; y < WIN_HEIGHT; y++)
	{
		for (int x = 0; x < WIN_WIDTH; x++)
		{
			info->img.data[y * WIN_WIDTH + x] = info->buf[y][x];// 한 줄에 있으므로
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int main_loop(t_cub *cub)
{
	raycasting(cub);
	draw(cub);

	return (0);
}

void	load_image(t_cub *info, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(info->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_cub *info)
{
	t_img	img;

	load_image(info, info->texture[0], "textures/eagle.xpm", &img);
	load_image(info, info->texture[1], "textures/redbrick.xpm", &img);
	load_image(info, info->texture[2], "textures/purplestone.xpm", &img);
	load_image(info, info->texture[3], "textures/wood.xpm", &img);
}

int main(int argc, char **argv)
{
	t_cub cub;
	init(&cub);

	for (int i = 0; i < WIN_HEIGHT; i++)
	{
		for (int j = 0; j < WIN_WIDTH; j++)
		{
			cub.buf[i][j] = 0;
		}
	}

	if (!(cub.texture = (int **)malloc(sizeof(int *) * 4)))
		return (-1);
	for (int i = 0; i < 4; i++)
	{
		if (!(cub.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth))))
			return (-1);
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < texHeight * texWidth; j++)
		{
			cub.texture[i][j] = 0;
		}
	}

	load_texture(&cub);

	cub.moveSpeed = 0.05;
	cub.rotSpeed = 0.05;

	cub.img.img = mlx_new_image(cub.mlx, WIN_WIDTH, WIN_HEIGHT);
	cub.img.data = (int *)mlx_get_data_addr(cub.img.img, &cub.img.bpp, &cub.img.size_l, &cub.img.endian);


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

void casting_floor_ceiling(t_cub *cub)
{
	int y;

    //Floor Casting
    y = 0;
    while (y < WIN_HEIGHT)
    {
        // rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
		float rayDirX0 = cub->dirX - cub->planeX;
		float rayDirY0 = cub->dirY - cub->planeY;
		float rayDirX1 = cub->dirX + cub->planeX;
		float rayDirY1 = cub->dirY + cub->planeY;

        // Current y position compared to the center of the screen (the horizon)
		int p = y - WIN_HEIGHT / 2;

		// Vertical position of the camera.
		float posZ = 0.5 * WIN_HEIGHT;

		// Horizontal distance from the camera to the floor for the current row.
		// 0.5 is the z position exactly in the middle between floor and ceiling.
		float rowDistance = posZ / p;

		// calculate the real world step vector we have to add for each x (parallel to camera plane)
		// adding step by step avoids multiplications with a weight in the inner loop
		float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / WIN_WIDTH;
		float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / WIN_WIDTH;

		// real world coordinates of the leftmost column. This will be updated as we step to the right.
		float floorX = cub->posX + rowDistance * rayDirX0;
		float floorY = cub->posY + rowDistance * rayDirY0;

        for(int x = 0; x < WIN_WIDTH; ++x)
		{
			// the cell coord is simply got from the integer parts of floorX and floorY
			int cellX = (int)(floorX);
			int cellY = (int)(floorY);

			// get the texture coordinate from the fractional part
			int tx = (int)(texWidth * (floorX - cellX)) & (texWidth - 1);
			int ty = (int)(texHeight * (floorY - cellY)) & (texHeight - 1);

			floorX += floorStepX;
			floorY += floorStepY;

			// choose texture and draw the pixel
			int floorTexture = 0;
			int ceilingTexture = 1;

			int color;

			// floor
			color = 0x004C99;//cub->texture[floorTexture][texWidth * ty + tx];
			//color = (color >> 1) & 8355711; // make a bit darker

			cub->buf[y][x] = color;

			//ceiling (symmetrical, at screenHeight - y - 1 instead of y)
			color = 0x3399FF;cub->texture[ceilingTexture][texWidth * ty + tx];
			//color = (color >> 1) & 8355711; // make a bit darker

			cub->buf[WIN_HEIGHT - y - 1][x] = color;
		}
        y++;
    }
}

void texturing_walls(t_cub *cub, int x, int mapX, int mapY, int side, double perpWallDist,\
					double rayDirX, double rayDirY, int lineHeight, int drawStart, int drawEnd)
{
	// texturing calculations
	int texNum = worldMap[mapX][mapY]; //맵 상의 텍스쳐 종류

	// calculate value of wallX
	// 벽의 int형 좌표가 아닌 double형 좌표로 벽의 정확히 어디에 부딪혔는지 나타낸다.
	// 텍스처를 적용할 때 어떤 x좌표를 사용해야하는지 판단할 떄 사용한다.
	double wallX;
	if (side == 0)
		wallX = cub->posY + perpWallDist * rayDirY; //?
	else
		wallX = cub->posX + perpWallDist * rayDirX; //?
	// 부딪힌 곳의 정확한 x, y값(double)에서 벽의 x, y값(int)을 빼서 판단할 수 있다.
	wallX -= floor(wallX);

	// x coordinate on the texture
	// 텍스처의 x좌표를 나타내는 texX 계산
	int texX = (int)(wallX * (double)texWidth);
	if (side == 0 && rayDirX > 0)
		texX = texWidth - texX - 1;
	if (side == 1 && rayDirY < 0)
		texX = texWidth - texX - 1;

	// How much to increase the texture coordinate perscreen pixel
	// 텍스처의 좌표를 수직선 상에 있는 좌표에 대해 얼마나 늘려야 하는지에 따라 결정된다.
	double step = 1.0 * texHeight / lineHeight;
	// Starting texture coordinate
	double texPos = (drawStart - WIN_HEIGHT / 2 + lineHeight / 2) * step;
	// 각 픽셀이 텍스처의 어떤 y 좌표 texY를 갖게 할 건지 정해주기 위해 y방향 반복문 실행
	for (int y = drawStart; y < drawEnd; y++)
	{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		int texY = (int)texPos & (texHeight - 1);
		texPos += step;
		int color = cub->texture[texNum][texHeight * texY + texX];
		// make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		/*if (side == 1)
			color = (color >> 1) & 8355711;*/
		cub->buf[y][x] = color;
	}
}

void raycasting(t_cub *cub)
{
	casting_floor_ceiling(cub);

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

		// calculate lowest and highest pixel to fill in current stripe
		// 벽의 중심은 화면의 중심에 있어야하고, 이 중심점이 화면 범위 아래에 놓여있다면 0으로, 화면 범위 밖에 놓여있다면 h - 1로 덮어씌운다.
		int drawStart = -lineHeight / 2 + WIN_HEIGHT / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WIN_HEIGHT / 2;
		if(drawEnd >= WIN_HEIGHT)
			drawEnd = WIN_HEIGHT - 1;

		texturing_walls(cub, x, mapX, mapY, side, perpWallDist, rayDirX, rayDirY, lineHeight, drawStart, drawEnd);
		x++;
	}
}