/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:03:43 by matraore          #+#    #+#             */
/*   Updated: 2020/12/18 22:50:31 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple			sum_tuples(t_tuple a, t_tuple b)
{
	t_tuple		c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	c.w = a.w + b.w;
	return (c);
}

t_tuple			sub_tuples(t_tuple a, t_tuple b)
{
	t_tuple		c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	c.w = a.w - b.w;
	return (c);
}

t_tuple			multi_tuples(double a, t_tuple b)
{
	t_tuple		c;

	c.x = a * b.x;
	c.y = a * b.y;
	c.z = a * b.z;
	c.w = a * b.w;
	return (c);
}

t_tuple			div_tuples(double a, t_tuple b)
{
	t_tuple		c;

	c.x = a / b.x;
	c.y = a / b.y;
	c.z = a / b.z;
	c.w = a / b.w;
	return (c);
}
