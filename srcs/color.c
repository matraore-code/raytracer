/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:50:45 by ashih             #+#    #+#             */
/*   Updated: 2018/04/11 07:16:01 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		draw_dot(int x, int y, t_vect3 *color, t_master *m)
{
	m->frame[x + y * WIN_WIDTH] =
		(ft_round_dbl(255.0 * (*color)[0]) << 16) |
		(ft_round_dbl(255.0 * (*color)[1]) << 8) |
		(ft_round_dbl(255.0 * (*color)[2]) << 0);
}

void		set_color(t_vect3 *color, int color_num)
{
	(*color)[0] = (double)((color_num >> 16) & 0xFF) / 255.0;
	(*color)[1] = (double)((color_num >> 8) & 0xFF) / 255.0;
	(*color)[2] = (double)((color_num >> 0) & 0xFF) / 255.0;
}

void		clamp_color(t_vect3 *color)
{
	CLAMP((*color)[0], 0.0, 1.0);
	CLAMP((*color)[1], 0.0, 1.0);
	CLAMP((*color)[2], 0.0, 1.0);
}
