/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 00:58:49 by ashih             #+#    #+#             */
/*   Updated: 2018/04/09 09:26:44 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		print_object(t_obj *obj, t_obj *selected)
{
	if (obj == selected)
		ft_printf("{cyan}{bold}%s{reset}:", obj->name);
	else
		ft_printf("{cyan}%s{reset}:", obj->name);
	ft_printf("\tk_diffuse = %.3f,\tk_specular = %.3f,\tphong_n = %.3f,\n",
		obj->k_diffuse, obj->k_specular, obj->phong_n);
	if (obj->type == SPHERE_OBJ)
		print_sphere_obj(obj);
	else if (obj->type == PLANE_OBJ)
		print_plane_obj(obj);
	else if (obj->type == DISK_OBJ)
		print_disk_obj(obj);
	else if (obj->type == CYLINDER_OBJ)
		print_cylinder_obj(obj);
	else if (obj->type == CONE_OBJ)
		print_cone_obj(obj);
}

void			print_all_objects(t_list *object_list, t_obj *selected)
{
	while (object_list)
	{
		print_object(object_list->content, selected);
		ft_printf("\n");
		object_list = object_list->next;
	}
}
