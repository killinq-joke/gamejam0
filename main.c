#include "cacland.h"

int	frame(t_params *p)
{
	(void)p;
	return (0);
}

void init(t_params *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "Cacland");
	p->background.i = mlx_xpm_file_to_image(p->mlx, "background.xpm", &p->background.width, &p->background.height);
	p->floor.i = mlx_xpm_file_to_image(p->mlx, "floor.xpm", &p->floor.width, &p->floor.height);
	mlx_put_image_to_window(p->mlx, p->win, p->background.i, 0, 0);
	mlx_put_image_to_window(p->mlx, p->win, p->floor.i, 0, HEIGHT - p->floor.height);
}

int main()
{
	t_params	p;

	init(&p);
	mlx_loop_hook(p.mlx, frame, &p);
	mlx_loop(p.mlx);
	return (0);
}