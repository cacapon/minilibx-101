/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:54:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/08 12:17:44 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static t_xpm_img _load_xpm(void *mlx)
{
	t_xpm_img	xpm;

	xpm = (t_xpm_img){.h=16, .w=16, .h_p=&(xpm.h), .w_p=&(xpm.w)};
	xpm.img[0] = mlx_xpm_file_to_image(mlx, "02-draw-map/plane.xpm", xpm.w_p, xpm.h_p);
	xpm.img[1] = mlx_xpm_file_to_image(mlx, "02-draw-map/wall.xpm", xpm.w_p, xpm.h_p);
	return (xpm);
}

static void _set_stage(void *mlx, void *win, t_xpm_img xpm)
{
	for (int y = 0; y<5; y++)
		for (int x = 0; x<5; x++)
		{
			if (x == 0 || y == 0 || x == 4 || y == 4)
				mlx_put_image_to_window(mlx, win, xpm.img[1], xpm.w*x, xpm.h*y);
			else
				mlx_put_image_to_window(mlx, win, xpm.img[0], xpm.w*x, xpm.h*y);
		}
}

int	main(void)
{
	void		*mlx;
	void		*win;
	t_xpm_img	xpm;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx-101-01 show window");
	xpm = _load_xpm(mlx);	
	_set_stage(mlx, win, xpm);
	mlx_loop(mlx);
	return (0);
}