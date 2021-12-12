#include "cacland.h"

void playerinit(t_params *p)
{
	p->player.x = 0;
	p->player.y = HEIGHT - p->floor.height;
}

void init(t_params *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "Cacland");
	p->background.i = mlx_xpm_file_to_image(p->mlx, "background.xpm", &p->background.width, &p->background.height);
	p->floor.i = mlx_xpm_file_to_image(p->mlx, "floor.xpm", &p->floor.width, &p->floor.height);
	mlx_put_image_to_window(p->mlx, p->win, p->background.i, 0, 0);
	mlx_put_image_to_window(p->mlx, p->win, p->floor.i, 0, HEIGHT - p->floor.height);
	playerinit(p);
}
