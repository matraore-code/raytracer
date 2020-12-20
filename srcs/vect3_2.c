/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:05:05 by ashih             #+#    #+#             */
/*   Updated: 2018/04/11 09:49:22 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		v_dot(t_vect3 *v1, t_vect3 *v2)
{
	t_vect3	p;

	p = *v1 * *v2;
	return (p[0] + p[1] + p[2]);
}

void		v_cross(t_vect3 *v1, t_vect3 *v2, t_vect3 *result)
{
	t_vect3 p;

	p[0] = (*v1)[1] * (*v2)[2] - (*v1)[2] * (*v2)[1];
	p[1] = (*v1)[2] * (*v2)[0] - (*v1)[0] * (*v2)[2];
	p[2] = (*v1)[0] * (*v2)[1] - (*v1)[1] * (*v2)[0];
	ft_memcpy(result, &p, sizeof(t_vect3));
}

void		v_mult(double scalar, t_vect3 *v, t_vect3 *result)
{
	t_vect3	mult;

	v_init(&mult, scalar, scalar, scalar);
	*result = *v * mult;
}

void		mult_matrix_vector(t_matrix *m, t_vect3 *v, t_vect3 *r)
{
	t_vect3	p;

	p[0] = v_dot(&m->r0, v);
	p[1] = v_dot(&m->r1, v);
	p[2] = v_dot(&m->r2, v);
	ft_memcpy(r, &p, sizeof(t_vect3));
}
