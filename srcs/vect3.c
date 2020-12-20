/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:05:05 by ashih             #+#    #+#             */
/*   Updated: 2018/04/11 09:47:49 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		v_init(t_vect3 *v, double x, double y, double z)
{
	(*v)[0] = x;
	(*v)[1] = y;
	(*v)[2] = z;
}

void		v_normalize(t_vect3 *v)
{
	double	p;

	p = v_dot(v, v);
	if (p > 0.0)
	{
		v_mult(1.0 / sqrt(p), v, v);
	}
}

double		v_dist(t_vect3 *src, t_vect3 *dst)
{
	t_vect3	v;
	double	p;

	v_subtract(dst, src, &v);
	p = v_dot(&v, &v);
	return (sqrt(p));
}

void		v_dir(t_vect3 *src, t_vect3 *dst, t_vect3 *dir)
{
	v_subtract(dst, src, dir);
	v_normalize(dir);
}

int			v_is_zero(t_vect3 *v)
{
	return ((*v)[0] == 0.0 && (*v)[1] == 0.0 && (*v)[2] == 0.0);
}
