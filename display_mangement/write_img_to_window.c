/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_img_to_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 00:43:01 by matraore          #+#    #+#             */
/*   Updated: 2020/12/20 09:46:42 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length +
			x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}



void			img_to_window()
{
	t_data		data;

	data.img = mlx_new_image(g_window.mlx_ptr, g_window.res.width,
			g_window.res.height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	my_mlx_pixel_put(&data, x, y, 0x00FF0000);
	mlx_put_image_to_window(g_window.mlx_ptr, g_window.win_ptr, data.img, x, y);
}
