#include <mlx.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "caclang.h"

#define WIDTH   1920
#define HEIGHT  1080
#define PI      3.14159265359

typedef struct
{
	void		*img;
	int			*buf;
	int			width;
	int			height;
}	t_img;

typedef struct
{
	void	*ptr;
	void	*win;
	void	*img;
	int		*buf;
	t_img	sprites[10];
}	t_mlx;

void	err(char *s)
{
	fprintf(stderr, "\033[31mError: %s\033[0m\n", s);
	exit(1);
}

t_img	load_img(t_mlx *mlx, char *filename)
{
	t_img	img;
	int		null;

	img.img = mlx_xpm_file_to_image(mlx->ptr, filename, &img.width, &img.height);
	if (img.img == NULL)
		err("could not load image");
	img.buf = (int *)mlx_get_data_addr(img.img, &null, &null, &null);
	return (img);
}

static inline int	isinside(int x, int y)
{
	return (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT);
}

void	draw_img(t_mlx *mlx, t_img *img, int ox, int oy, float rot)
{
	int		x, y;
	int		X, Y;
	float	hx, hy;
	float	dx, dy;
	int		*buf;
	float	sinR = sin(rot), cosR = cos(rot);

	y = -1;
	buf = img->buf;
	hx = (float)img->width / 2.0;
	hy = (float)img->height / 2.0;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
		{
			if (*buf)
			{
				dx = x - hx;
				dy = (float)y - hy;
				X = ox + dx * cosR - dy * sinR;
				Y = oy + dx * sinR + dy * cosR;
				if (isinside(X, Y))
					mlx->buf[X + Y * WIDTH] = *buf;
				if (isinside(X - 1, Y - 1))
				{
					mlx->buf[X + Y * WIDTH - 1 - WIDTH] = *buf;
					mlx->buf[X + Y * WIDTH - 1] = *buf;
					mlx->buf[X + Y * WIDTH - WIDTH] = *buf;
				}
			}
			buf++;
		}
	}
}

void	mlx_clear_image(t_mlx *mlx)
{
	int	i;
	int	*buf;
	int	floor_height;

	i = WIDTH * HEIGHT;
	floor_height = WIDTH * 250;
	buf = mlx->buf;
	srand(24082006);
	while (i--)
	{
		if (i < floor_height)
			*buf++ = (int)(255.0 * 255.0 * 255.0 * perlin(i / (float)(WIDTH) / (float)(HEIGHT * 10), (i % WIDTH) / (float)WIDTH * 10));
		//{
		//	if (i % (WIDTH + 100) < 50)
		//		*buf++ = 0xaaaaaa + (rand() & 0x0f0f0f);
		//	else
		//		*buf++ = 0x0000ff;
		//}
		else
			*buf++ = 0x111225;
	}
}

int	update(t_mlx *mlx)
{
	static float	rot = 0.0;

	mlx_clear_image(mlx);
	rot += 0.01;
	draw_img(mlx, mlx->sprites, 32, 32, rot);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	return (0);
}

int	main()
{
	t_mlx	mlx;
	int		null;

	puts("initializing window");
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "Cacland");

	puts("creating image buffer");
	mlx.img = mlx_new_image(&mlx.ptr, WIDTH, HEIGHT);
	mlx.buf = (int *)mlx_get_data_addr(mlx.img, &null, &null, &null);

	puts("loading image");
	mlx.sprites[0] = load_img(&mlx, "./test.xpm");

	mlx_loop_hook(mlx.ptr, update, &mlx);
	mlx_loop(mlx.ptr);
}
