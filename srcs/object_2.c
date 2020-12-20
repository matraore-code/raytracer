/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 00:58:49 by ashih             #+#    #+#             */
/*   Updated: 2018/04/11 07:22:29 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	print_sphere_obj(t_obj *obj)
{
	ft_printf("\t\tpos.x = %.3f\tpos.y = %.3f\tpos.z = %.3f,\n",
		obj->center[0], obj->center[1], obj->center[2]);
	ft_printf("\t\tradius = %.3f\n", obj->radius);
}

void	print_plane_obj(t_obj *obj)
{
	ft_printf("\t\tpos.x = %.3f\tpos.y = %.3f\tpos.z = %.3f,\n",
		obj->center[0], obj->center[1], obj->center[2]);
	ft_printf("\t\tnormal.x = %.3f\tnormal.y = %.3f\tnormal.z = %.3f\n",
		obj->normal[0], obj->normal[1], obj->normal[2]);
}

void	print_disk_obj(t_obj *obj)
{
	ft_printf("\t\tpos.x = %.3f\tpos.y = %.3f\tpos.z = %.3f,\n",
		obj->center[0], obj->center[1], obj->center[2]);
	ft_printf("\t\tnormal.x = %.3f\tnormal.y = %.3f\tnormal.z = %.3f,\n",
		obj->normal[0], obj->normal[1], obj->normal[2]);
	ft_printf("\t\tradius = %.3f\n", obj->radius);
}

void	print_cylinder_obj(t_obj *obj)
{
	ft_printf("\t\tpos.x = %.3f\tpos.y = %.3f\tpos.z = %.3f,\n",
		obj->center[0], obj->center[1], obj->center[2]);
	ft_printf("\t\tdir.x = %.3f\tdir.y = %.3f\tdir.z = %.3f\n",
		obj->dir[0], obj->dir[1], obj->dir[2]);
}

void	print_cone_obj(t_obj *obj)
{
	ft_printf("\t\tpos.x = %.3f\tpos.y = %.3f\tpos.z = %.3f,\n",
		obj->center[0], obj->center[1], obj->center[2]);
	ft_printf("\t\tdir.x = %.3f\tdir.y = %.3f\tdir.z = %.3f,\n",
		obj->dir[0], obj->dir[1], obj->dir[2]);
	ft_printf("\t\thalf_angle = %.3f\n", obj->half_angle);
}
