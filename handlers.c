#include "cacland.h"

int destroy(t_params *p)
{
	mlx_destroy_image(p->mlx, p->background.i);
	mlx_destroy_image(p->mlx, p->floor.i);
	mlx_destroy_window(p->mlx, p->win);
	exit(0);
	return (0);
}

int keyhandler(int key, t_params *p)
{
	if (key == W)
	{
		//rotate gun
	}
	if (key == A)
	{
		//rotate gun && player
	}
	if (key == D)
	{
		//rotate gun && player
	}
	if (key == SPACE)
	{
		//jump();
	}
	if (key == ESC)
	{
		destroy(p);
	}
	(void)p;
	return (0);
}