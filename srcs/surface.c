/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 07:23:12 by ashih             #+#    #+#             */
/*   Updated: 2018/04/10 04:50:52 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		get_surface_cylinder(t_ray *ray, t_vect3 *hit_point,
	t_vect3 *hit_normal)
{
	t_vect3		v;
	double		s;

	v_subtract(hit_point, &ray->hit_obj->center, &v);
	s = v_dot(&v, &ray->hit_obj->dir);
	v_mult(s, &ray->hit_obj->dir, &v);
	v_add(&ray->hit_obj->center, &v, &v);
	v_subtract(hit_point, &v, hit_normal);
}

static void		get_surface_cone(t_ray *ray, t_vect3 *hit_point,
	t_vect3 *hit_normal)
{
	t_vect3		x;
	double		m;
	double		k;

	v_subtract(&ray->orig, &ray->hit_obj->center, &x);
	m = ray->t * v_dot(&ray->dir, &ray->hit_obj->dir) +
		v_dot(&x, &ray->hit_obj->dir);
	k = tan(DEG_TO_RAD(ray->hit_obj->half_angle));
	v_mult(m, &ray->hit_obj->dir, hit_normal);
	v_mult(1.0 + k * k, hit_normal, hit_normal);
	v_add(&ray->hit_obj->center, hit_normal, hit_normal);
	v_subtract(hit_point, hit_normal, hit_normal);
}

void			get_surface(t_ray *ray, t_vect3 *hit_point, t_vect3 *hit_normal)
{
	if (ray->hit_obj->type == SPHERE_OBJ)
		v_subtract(hit_point, &ray->hit_obj->center, hit_normal);
	else if (ray->hit_obj->type == PLANE_OBJ || ray->hit_obj->type == DISK_OBJ)
		ft_memcpy(hit_normal, &ray->hit_obj->normal, sizeof(t_vect3));
	else if (ray->hit_obj->type == CYLINDER_OBJ)
		get_surface_cylinder(ray, hit_point, hit_normal);
	else if (ray->hit_obj->type == CONE_OBJ)
		get_surface_cone(ray, hit_point, hit_normal);
	v_normalize(hit_normal);
}
