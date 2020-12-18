/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:25:17 by matraore          #+#    #+#             */
/*   Updated: 2020/12/18 21:00:36 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple		create_point(double x, double y, double z)
{
	t_tuple	p;

	p.x = x;
	p.y = y;
	p.z = z;
	p.w = 1;
	return (p);
}

t_tuple		create_vector(double x, double y, double z)
{
	t_tuple	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = 0;
	return (v);
}

int			comparingTuples(t_tuple a, t_tuple b)
{
	if (equal(a.x, b.x) && equal(a.y, b.y)
			&& equal(a.z, b.z) && equal(a.w, b.w))
		return (1);
	return (0);
}

