/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:48:28 by matraore          #+#    #+#             */
/*   Updated: 2020/12/20 08:19:40 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <mlx.h>
# include "../math_tools/math.h"

typedef	struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef	struct	s_reso
{
	int			width;
	int			height;
}				t_reso;

typedef	struct	s_window
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*win_title;
	t_reso		res;
}				t_win;

typedef	struct	s_canvas
{
	int			width;
	int			height;
	int			color;
}				t_canvas;

t_win			g_window;
void			init_window();
void			open_window();
int				run_win();
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_canvas		create_canvas(int x, int y);
void			img_to_window(int x, int y, t_canvas canvas);

#endif

// main
// t_scene scene = load_scene() lire le fichier .rt and create the scene , 
// void  * render_buffer = render(scene);
// if (--save) --> ecrire_bmp(render_buffer, scene)
// hanlder.buffer = render_buffer // je garde le pointeur juste pour faire free
// alloc les image par mlx_create_image, et copie render_buffer vers les images
// ecrit la premier image dans window, mlx_put_ima...
// mlx_hook(mlx_ptr, callback)
//
// callback(
// 	scene->index .. define le cameraas 
// 	scene->index++
// 	mlx_put_image_to_window(hanlder.images[scene->index])
// )
