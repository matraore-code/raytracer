/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:01:42 by ashih             #+#    #+#             */
/*   Updated: 2018/04/11 07:55:06 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				trace(t_ray *ray, t_list *obj_list)
{
	t_obj		*obj;
	double		t;

	while (obj_list != 0)
	{
		obj = obj_list->content;
		if (obj->intersect(obj, ray, &t) && t < ray->t)
		{
			ray->t = t;
			ray->hit_obj = obj;
			ft_memcpy(&ray->color, &obj->color, sizeof(t_vect3));
		}
		obj_list = obj_list->next;
	}
	return (ray->hit_obj != 0);
}

void			raycast(t_ray *ray, t_list *obj_list, t_list *light_list)
{
	t_vect3		hit_point;
	t_vect3		hit_normal;
	t_light		*light;
	int			count;

	if (!trace(ray, obj_list))
		return (set_color(&ray->final_color, BG_COLOR));
	count = light_count(light_list);
	v_mult(ray->t, &ray->dir, &hit_point);
	v_add(&ray->orig, &hit_point, &hit_point);
	get_surface(ray, &hit_point, &hit_normal);
	while (light_list)
	{
		light = light_list->content;
		if (light->on_state && !shadow_cast(&hit_point, light, obj_list))
			add_color_from_light(ray, light, &hit_point, &hit_normal);
		light_list = light_list->next;
	}
	if (count != 0)
		v_mult(1.0 / (double)count, &ray->final_color, &ray->final_color);
	clamp_color(&ray->final_color);
}

void			init_ray(t_ray *ray, double x, double y, t_camera *cam)
{
	double		screen_x;
	double		screen_y;
	double		camera_x;
	double		camera_y;

	ft_bzero(ray, sizeof(t_ray));
	ray->t = INFINITY;
	ft_memcpy(&ray->orig, &cam->pos, sizeof(t_vect3));
	screen_x = 2.0 * ((x + 0.5) / WIN_WIDTH) - 1.0;
	screen_y = 1.0 - 2.0 * ((y + 0.5) / WIN_HEIGHT);
	camera_x = screen_x * ((double)WIN_WIDTH / (double)WIN_HEIGHT) *
		tan(DEG_TO_RAD(cam->fov_h / 2.0));
	camera_y = screen_y * tan(DEG_TO_RAD(cam->fov_v / 2.0));
	v_init(&ray->dir, camera_x, camera_y, -1.0);
	mult_matrix_vector(&cam->rot_matrix, &ray->dir, &ray->dir);
	v_normalize(&ray->dir);
}
