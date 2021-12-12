#include "cacland.h"

void sceneinit(t_params *p)
{
	p->player.x = 0;
	p->player.y = HEIGHT - p->floor.height - p->player.i.height;
	p->boss.x = WIDTH - p->boss.i.width;
	p->boss.y = HEIGHT - p->floor.height - p->boss.i.height;
}

void init(t_params *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "Cacland");
	p->background.i = mlx_xpm_file_to_image(p->mlx, "./textures/background.xpm", &p->background.width, &p->background.height);
	p->floor.i = mlx_xpm_file_to_image(p->mlx, "./textures/floor.xpm", &p->floor.width, &p->floor.height);
	p->boss.i.i = mlx_xpm_file_to_image(p->mlx, "./textures/boss.xpm", &p->boss.i.width, &p->boss.i.height);
	p->player.i.i = mlx_xpm_file_to_image(p->mlx, "./textures/player.xpm", &p->player.i.width, &p->player.i.height);
	sceneinit(p);
}
