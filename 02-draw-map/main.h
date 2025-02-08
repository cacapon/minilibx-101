/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:28:28 by ttsubo            #+#    #+#             */
/*   Updated: 2025/02/08 11:42:24 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "mlx.h"

typedef struct e_xpm_img
{
	void	*img[2];
	int		w;
	int		h;
	int		*w_p;
	int		*h_p;
}			t_xpm_img;

#endif