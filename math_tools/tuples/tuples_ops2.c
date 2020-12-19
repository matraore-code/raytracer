/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_ops2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:06:09 by matraore          #+#    #+#             */
/*   Updated: 2020/12/19 00:34:01 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

double			magnetude_vector(t_tuple vect)
{
	double		mag;

	mag = sqrt((vect.x * vect.x) + (vect.y * vect.y) + (vect.z * vect.z));
	return (mag);
}

t_tuple			normalize_vector(t_tuple vect)
{
	t_tuple		unit_vect;
	double		mag;

	mag = 1 / magnetude_vector(vect);
	unit_vect.x = vect.x / mag;
	unit_vect.y = vect.y / mag;
	unit_vect.z = vect.z / mag;
	unit_vect.w = 0;
	return (unit_vect);
}

double			scalar_tuples(t_tuple a, t_tuple b)
{
	double		c;

	c = a.x * b.x + a.y * b.y + a.z * b.z;
	return (c);
}

t_tuple			cross_tuples(t_tuple a, t_tuple b)
{
	t_tuple		c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = a.z * b.x - a.x * b.z;
	c.z = a.x * b.y - a.y * b.x;
	return (vector(c));
}
