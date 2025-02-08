/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:28:28 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/08 13:37:15 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "mlx.h"
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdbool.h>

# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00

typedef struct s_xpm_img	t_xpm_img;

typedef enum e_key_code
{
	NONE = 0,
	KEY_ESC = XK_Escape,
	KEY_UP = XK_Up,
	KEY_DOWN = XK_Down,
	KEY_LEFT = XK_Left,
	KEY_RIGHT = XK_Right,
	KEY_W = XK_w,
	KEY_A = XK_a,
	KEY_S = XK_s,
	KEY_D = XK_d,
}							t_key_code;

typedef struct e_key_flg
{
	bool up;
	bool down;
	bool left;
	bool right;
}	t_key_flg;

typedef struct s_sys
{
	void					*mlx;
	void					*win;
	t_xpm_img				*xpm;
	t_key_flg				key_flg;
}							t_sys;

typedef struct s_xpm_img
{
	void					*img[2];
	int						w;
	int						h;
	int						*w_p;
	int						*h_p;
}							t_xpm_img;

//input

#endif
