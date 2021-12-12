#include "cacland.h"

int	frame()
{
	return (0);
}

int main()
{
	t_params	p;

	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIDTH, HEIGHT, (char*)"Cacland");
	mlx_loop_hook(p.mlx, frame, &p);
	mlx_loop(p.mlx);
	return (0);
}