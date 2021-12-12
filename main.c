#include "cacland.h"

void	playermove(t_params *p)
{
	static	int		jumpunit;
	static	bool	goback;

	if (p->player.mover)
		p->player.x += MOVESPEED;
	if (p->player.movel)
		p->player.x -= MOVESPEED;
	if (p->player.jumping || jumpunit != 0)
	{
		p->player.y = p->player.y + jumpunit;
		if (jumpunit < MAXJUMP && !goback)
			jumpunit += MAXJUMP / 10;
		if (goback)
			jumpunit -= MAXJUMP / 10;
		if (jumpunit == MAXJUMP)
			goback = true;
		if (jumpunit == 0)
			goback = false;
		p->player.y = p->player.y - jumpunit;
	}
}

int	frame(t_params *p)
{
	playermove(p);
	mlx_put_image_to_window(p->mlx, p->win, p->background.i, 0, 0);
	mlx_put_image_to_window(p->mlx, p->win, p->floor.i, 0, HEIGHT - p->floor.height);
	mlx_put_image_to_window(p->mlx, p->win, p->boss.i.i, p->boss.x, p->boss.y);
	mlx_put_image_to_window(p->mlx, p->win, p->player.i.i, p->player.x, p->player.y);
	return (0);
}

int main()
{
	t_params	p;

	init(&p);
	mlx_hook(p.win, 17, 0L, destroy, &p);
	mlx_hook(p.win, 02, (1L<<0), keypress, &p);
	mlx_hook(p.win, 03, (1L<<1), keyrelease, &p);
	mlx_hook(p.win, 04, (1L<<2), buttonpress, &p);
	mlx_loop_hook(p.mlx, frame, &p);
	mlx_loop(p.mlx);
	return (0);
}