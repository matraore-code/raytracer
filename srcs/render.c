/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:01:42 by ashih             #+#    #+#             */
/*   Updated: 2018/04/11 07:54:54 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		init_light_rotation(t_list *light_list)
{
	t_light		*light;

	while (light_list)
	{
		light = light_list->content;
		if (light->type == DISTANT_LIGHT)
		{
			init_rot_matrix(&light->rot_matrix, light->rot_x, light->rot_y,
				light->rot_z);
			mult_matrix_vector(&light->rot_matrix, &light->dir_0, &light->dir);
		}
		light_list = light_list->next;
	}
}

static void		init_obj_rotation(t_list *obj_list)
{
	t_obj		*obj;

	while (obj_list)
	{
		obj = obj_list->content;
		init_rot_matrix(&obj->rot_matrix, obj->rot_x, obj->rot_y, obj->rot_z);
		if (obj->type == CYLINDER_OBJ || obj->type == CONE_OBJ)
			mult_matrix_vector(&obj->rot_matrix, &obj->dir_0, &obj->dir);
		else if (obj->type == PLANE_OBJ || obj->type == DISK_OBJ)
			mult_matrix_vector(&obj->rot_matrix, &obj->normal_0, &obj->normal);
		obj_list = obj_list->next;
	}
}

void			render(t_master *m)
{
	init_rot_matrix(&m->cam.rot_matrix, m->cam.rot_x, m->cam.rot_y,
		m->cam.rot_z);
	init_light_rotation(m->light_list);
	init_obj_rotation(m->obj_list);
	render_th_master(m);
	mlx_put_image_to_window(m->mlx, m->win, m->img, 0, 0);
	print_info(m);
}

void			print_info(t_master *m)
{
	ft_printf("{magenta}FOV_H{reset} = %.3f,\t{magenta}FOV_V{reset} = %.3f\n",
		m->cam.fov_h, m->cam.fov_v);
	ft_printf("{magenta}Cam Position{reset}\tx = %.3f,\ty = %.3f,\tz = %.3f\n",
		m->cam.pos[0], m->cam.pos[1], m->cam.pos[2]);
	ft_printf("{magenta}Cam Rotation{reset}\tx = %.3f,\ty = %.3f,\tz = %.3f\n",
		m->cam.rot_x, m->cam.rot_y, m->cam.rot_z);
	ft_printf("\n");
	print_all_lights(m->light_list, m->light);
	print_all_objects(m->obj_list, m->obj);
}
