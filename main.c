#include "cacland.h"

int	frame(t_params *p)
{
	(void)p;
	return (0);
}

int main()
{
	t_params	p;

	init(&p);
	mlx_loop_hook(p.mlx, frame, &p);
	mlx_hook(p.win, 17, 0L, destroy, &p);
	mlx_hook(p.win, 02, (1L<<0), keyhandler, &p);
	mlx_loop(p.mlx);
	return (0);
}