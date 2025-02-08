/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:54:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/08 13:37:25 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_xpm_img *_load_xpm(void *mlx)
{
	t_xpm_img	*xpm;

	xpm = calloc(1, sizeof(t_xpm_img));
	xpm->h = 16;
	xpm->w = 16;
	xpm->h_p = &(xpm->h);
	xpm->w_p = &(xpm->w);
	xpm->img[0] = mlx_xpm_file_to_image(mlx, "02-draw-map/plane.xpm", xpm->w_p, xpm->h_p);
	xpm->img[1] = mlx_xpm_file_to_image(mlx, "02-draw-map/wall.xpm", xpm->w_p, xpm->h_p);
	return (xpm);
}

static void _set_stage(void *mlx, void *win, t_xpm_img *xpm)
{
	for (int y = 0; y<5; y++)
		for (int x = 0; x<5; x++)
		{
			if (x == 0 || y == 0 || x == 4 || y == 4)
				mlx_put_image_to_window(mlx, win, xpm->img[1], xpm->w*x, xpm->h*y);
			else
				mlx_put_image_to_window(mlx, win, xpm->img[0], xpm->w*x, xpm->h*y);
		}
}

static int _draw(t_sys *sys)
{
	mlx_clear_window(sys->mlx, sys->win);
	_set_stage(sys->mlx, sys->win, sys->xpm);
	if (sys->key_flg.up == true)
		mlx_string_put(sys->mlx, sys->win, 0, 16*6, WHITE, "key:UP");
	else if (sys->key_flg.left == true)
		mlx_string_put(sys->mlx, sys->win, 0, 16*6, WHITE, "key:LEFT");
	else if (sys->key_flg.down == true)
		mlx_string_put(sys->mlx, sys->win, 0, 16*6, WHITE, "key:DOWN");
	else if (sys->key_flg.right == true)
		mlx_string_put(sys->mlx, sys->win, 0, 16*6, WHITE, "key:RIGHT");
	return (0);
}

static int _key_press(t_key_code keycode, t_sys *sys)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_W || keycode == KEY_UP)
		sys->key_flg.up = true;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		sys->key_flg.left = true;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		sys->key_flg.down = true;
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		sys->key_flg.right = true;
	return (0);
}

static int _key_rel(int keycode, t_sys *sys)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		sys->key_flg.up = false;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		sys->key_flg.left = false;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		sys->key_flg.down = false;
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		sys->key_flg.right = false;
	return (0);
}

int	main(void)
{
	t_sys		sys;

	sys.mlx = mlx_init();
	sys.win = mlx_new_window(sys.mlx, 500, 500, "mlx-101-01 show window");
	sys.xpm = _load_xpm(sys.mlx);
	_set_stage(sys.mlx, sys.win, sys.xpm);
	mlx_loop_hook(sys.mlx, _draw, &sys);
	mlx_hook(sys.win, 2, 1L << 0, _key_press, &sys);
	mlx_hook(sys.win, 3, 1L << 1, _key_rel, &sys);
	mlx_loop(sys.mlx);
	return (0);
}