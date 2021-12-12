#include "cacland.h"

int	frame(t_params *p)
{
	
	return (0);
}

void init(t_params *p)
{
	t_img	i;

	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "Cacland");
	i.i = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->background = &i;
	p->background->addr = mlx_get_data_addr(i.i, &i.bits_per_pixel, &i.line_length,
								&i.endian);
}

int main()
{
	t_params	p;

	init(&p);
	mlx_loop_hook(p.mlx, frame, &p);
	mlx_loop(p.mlx);
	return (0);
}