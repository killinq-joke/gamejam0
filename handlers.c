#include "cacland.h"

int destroy(t_params *p)
{
	mlx_destroy_image(p->mlx, p->background.i);
	mlx_destroy_image(p->mlx, p->floor.i);
	mlx_destroy_window(p->mlx, p->win);
	exit(0);
	return (0);
}

int keypress(int key, t_params *p)
{
	if (key == W)
	{
		//rotate gun
		p->player.aimup = true;
	}
	if (key == A)
	{
		p->player.movel = true;
		//rotate gun && player
	}
	if (key == D)
	{
		p->player.mover = true;
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

int keyrelease(int key, t_params *p)
{
	if (key == W)
	{
		p->player.aimup = false;
		//rotate gun
	}
	if (key == A)
	{
		p->player.movel = false;
		//rotate gun && player
	}
	if (key == D)
	{
		p->player.mover = false;
		//rotate gun && player
	}
	return (0);
}

int	buttonpress(int button, int x, int y, t_params *p)
{
	printf("%d\n", button);
	(void)x;
	(void)y;
	if (button == LCLICK)
		p->player.shooting = true;
	if (button == RCLICK && !p->player.shooting)
	{
		//shoot special attack
	}
	if (button == SCROLLD || button == SCROLLU)
	{
		//change weapon
	}
	return (0);
}

int	buttonrelease(int button, int x, int y, t_params *p)
{
	printf("%d\n", button);
	(void)x;
	(void)y;
	if (button == LCLICK)
		p->player.shooting = false;
	if (button == RCLICK && !p->player.shooting)
	{
		//shoot special attack
	}
	if (button == SCROLLD || button == SCROLLU)
	{
		//change weapon
	}
	return (0);
}