#ifndef CACLAND_H
# define CACLAND_H
// # include <mlx.h>
# include "./minilibx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <time.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080
# define W 13
# define A 0
# define S 1
# define D 2
# define R 15
# define SPACE 49
# define ESC 53
# define LCLICK 1
# define RCLICK 2
# define SCROLLD 4
# define SCROLLU 5
# define MAXJUMP 200
# define MOVESPEED 10

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

typedef struct s_boss
{
	float	x;
	float	y;
	t_img	i;
}				t_boss;

typedef struct s_player
{
	float	x;
	float	y;
	t_img	i;
	bool	aimup;
	bool	mover;
	bool	movel;
	bool	shooting;
	bool	jumping;
	int		life;
}				t_player;

typedef struct s_params
{
	void *mlx;
	void *win;
	t_img background;
	t_img floor;
	t_boss boss;
	t_player player;
}				t_params;

int destroy(t_params *p);
int	buttonpress(int button, int x, int y, t_params *p);
int keypress(int key, t_params *p);
int	keyrelease(int key, t_params *p);
void playerinit(t_params *p);
void sceneinit(t_params *p);
void init(t_params *p);

#endif