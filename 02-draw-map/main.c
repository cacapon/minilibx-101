/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:54:51 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/06 16:35:06 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <math.h>

static void scale(void *mlx, t_xpm_img *img, int scale)
{
	int bits_per_pixel;
	int size_line;
	int endian;
	char *data;
	
}

int	main(void)
{
	void		*mlx;
	void		*win;
	t_xpm_img	xpm;
	int			xpm_h;
	int			xpm_w;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx-101-01 show window");
	xpm_h = 16;
	xpm_w = 16;
	xpm.img[0] = mlx_xpm_file_to_image(mlx, "02-draw-map/plane.xpm", &xpm_w, &xpm_h);
	xpm.img[1] = mlx_xpm_file_to_image(mlx, "02-draw-map/wall.xpm", &xpm_w, &xpm_h);
	for (int y = 0; y<5; y++)
		for (int x = 0; x<5; x++)
		{
			if (x == 0 || y == 0 || x == 4 || y == 4)
				mlx_put_image_to_window(mlx, win, xpm.img[1], xpm_w*x, xpm_h*y);
			else
				mlx_put_image_to_window(mlx, win, xpm.img[0], xpm_w*x, xpm_h*y);
		}
	mlx_loop(mlx);
	return (0);
}