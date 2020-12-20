/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 00:13:48 by ashih             #+#    #+#             */
/*   Updated: 2018/04/10 04:45:51 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				sphere_intersect(t_obj *obj, t_ray *ray, double *t)
{
	t_vect3		l;
	t_quadratic	q;

	v_subtract(&ray->orig, &obj->center, &l);
	q.a = 1.0;
	q.b = 2.0 * v_dot(&ray->dir, &l);
	q.c = v_dot(&l, &l) - SQ(obj->radius);
	return (solve_quadratic(&q, t));
}

int				plane_intersect(t_obj *obj, t_ray *ray, double *t)
{
	t_vect3		pl;
	double		denom;
	double		temp;

	denom = v_dot(&obj->normal, &ray->dir);
	if (fabs(denom) > TINY_VALUE)
	{
		v_subtract(&obj->center, &ray->orig, &pl);
		temp = v_dot(&pl, &obj->normal) / denom;
		if (temp >= 0)
		{
			*t = temp;
			return (1);
		}
	}
	return (0);
}

int				disk_intersect(t_obj *obj, t_ray *ray, double *t)
{
	double		temp;
	t_vect3		p;
	t_vect3		v;

	if (plane_intersect(obj, ray, &temp))
	{
		v_mult(temp, &ray->dir, &p);
		v_add(&ray->orig, &p, &p);
		v_subtract(&p, &obj->center, &v);
		if (v_dot(&v, &v) <= SQ(obj->radius))
		{
			*t = temp;
			return (1);
		}
	}
	return (0);
}

/*
** REFERENCE
** https://mrl.nyu.edu/~dzorin/rend05/lecture2.pdf
*/

int				cylinder_intersect(t_obj *obj, t_ray *ray, double *t)
{
	t_quadratic	q;
	t_vect3		dp;
	double		scal_a;
	t_vect3		vect_a;
	t_vect3		vect_b;

	v_subtract(&ray->orig, &obj->center, &dp);
	scal_a = v_dot(&ray->dir, &obj->dir);
	v_mult(scal_a, &obj->dir, &vect_a);
	v_subtract(&ray->dir, &vect_a, &vect_a);
	q.a = v_dot(&vect_a, &vect_a);
	scal_a = v_dot(&dp, &obj->dir);
	v_mult(scal_a, &obj->dir, &vect_b);
	v_subtract(&dp, &vect_b, &vect_b);
	q.b = 2.0 * v_dot(&vect_a, &vect_b);
	q.c = v_dot(&vect_b, &vect_b) - obj->radius * obj->radius;
	return (solve_quadratic(&q, t));
}

/*
** REFERENCE:
** http://lousodrome.net/blog/light/2017/01/03/intersection-of-a-ray-and-a-cone/
*/

int				cone_intersect(t_obj *obj, t_ray *ray, double *t)
{
	t_quadratic	q;
	double		rad;
	t_vect3		co;

	rad = DEG_TO_RAD(obj->half_angle);
	v_subtract(&ray->orig, &obj->center, &co);
	q.a = SQ(v_dot(&ray->dir, &obj->dir)) - SQ(cos(rad));
	q.b = 2.0 * (v_dot(&ray->dir, &obj->dir) * v_dot(&co, &obj->dir) -
		v_dot(&ray->dir, &co) * SQ(cos(rad)));
	q.c = SQ(v_dot(&co, &obj->dir)) - v_dot(&co, &co) * SQ(cos(rad));
	return (solve_quadratic(&q, t));
}
