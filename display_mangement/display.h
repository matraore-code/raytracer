/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:48:28 by matraore          #+#    #+#             */
/*   Updated: 2020/12/19 03:20:12 by matraore         ###   ########.fr       */
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
