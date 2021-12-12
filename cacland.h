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
}				t_img;

typedef struct s_params
{
	void *mlx;
	void *win;
	t_img *background;
}				t_params;

#endif