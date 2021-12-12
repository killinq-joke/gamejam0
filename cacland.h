#ifndef CACLAND_H
# define CACLAND_H
# define WIDTH 1920
# define HEIGHT 1080
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_img
{
	void	*i;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_player
{
	float	x;
	float	y;
	t_img	i;
}				t_player;

typedef struct s_params
{
	void *mlx;
	void *win;
	t_img background;
	t_img floor;
}				t_params;

#endif