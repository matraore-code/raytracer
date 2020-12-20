/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:01:42 by ashih             #+#    #+#             */
/*   Updated: 2018/04/10 04:50:01 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		shadow_trace(t_ray *shadow_ray, t_list *obj_list)
{
	t_obj		*obj;
	double		t;

	while (obj_list != 0)
	{
		obj = obj_list->content;
		if (obj->intersect(obj, shadow_ray, &t) && t < shadow_ray->t)
			return (1);
		obj_list = obj_list->next;
	}
	return (0);
}

int				shadow_cast(t_vect3 *hit_point, t_light *light,
	t_list *obj_list)
{
	t_ray		shadow_ray;
	t_vect3		temp;

	ft_bzero(&shadow_ray, sizeof(t_ray));
	ft_memcpy(&shadow_ray.orig, hit_point, sizeof(t_vect3));
	if (light->type == DISTANT_LIGHT)
	{
		ft_memcpy(&shadow_ray.dir, &light->dir, sizeof(t_vect3));
		v_mult(-1.0, &shadow_ray.dir, &shadow_ray.dir);
		shadow_ray.t = INFINITY;
	}
	else
	{
		v_dir(hit_point, &light->pos, &shadow_ray.dir);
		shadow_ray.t = v_dist(hit_point, &light->pos);
	}
	v_mult(SHADOW_BIAS, &shadow_ray.dir, &temp);
	v_add(&temp, &shadow_ray.orig, &shadow_ray.orig);
	return (shadow_trace(&shadow_ray, obj_list));
}

static void		find_reflection(t_vect3 *light_dir, t_vect3 *normal,
	t_vect3 *reflect)
{
	t_vect3		temp;

	v_mult(2.0 * v_dot(light_dir, normal), normal, &temp);
	v_subtract(light_dir, &temp, &temp);
	ft_memcpy(reflect, &temp, sizeof(t_vect3));
}

void			add_color_from_light(t_ray *ray, t_light *light,
	t_vect3 *hit_point, t_vect3 *hit_normal)
{
	t_vect3		light_dir;
	t_vect3		neg_dir;
	t_vect3		reflect;
	t_vect3		color;
	double		mult;

	if (light->type == DISTANT_LIGHT)
		ft_memcpy(&light_dir, &light->dir, sizeof(t_vect3));
	else
		v_dir(&light->pos, hit_point, &light_dir);
	v_mult(-1.0, &light_dir, &neg_dir);
	mult = v_dot(hit_normal, &neg_dir);
	if (mult <= 0.0)
		return ;
	v_mult(ray->hit_obj->k_diffuse * mult * light->intensity, &ray->color,
		&color);
	v_add(&color, &ray->final_color, &ray->final_color);
	find_reflection(&light_dir, hit_normal, &reflect);
	v_mult((ray->hit_obj->k_specular) * light->intensity *
		pow(MAX(0.0, v_dot(&reflect, &neg_dir)), ray->hit_obj->phong_n),
		&light->color, &color);
	v_add(&color, &ray->final_color, &ray->final_color);
}
