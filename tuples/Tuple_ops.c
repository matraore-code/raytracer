/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TupleOps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:03:43 by matraore          #+#    #+#             */
/*   Updated: 2020/11/12 03:29:23 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"


t_tuple sumTuples(t_tuple a, t_tuple b)
{
    t_tuple c;

    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    c.w = a.w + b.w;
    return (c);
}

t_tuple subTuples(t_tuple a, t_tuple b)
{
    t_tuple c;

    c.x = a.x - b.x;
    c.y = a.y - b.y;
    c.z = a.z - b.z;
    c.w = a.w - b.w;
    return (c);
}

t_tuple multiTuples(double a, t_tuple b)
{
    t_tuple c;

    c.x = a * b.x;
    c.y = a * b.y;
    c.z = a * b.z;
    c.w = a * b.w;
    return (c);
}

t_tuple divTuples(double a, t_tuple b)
{
    t_tuple c;

    c.x = a / b.x;
    c.y = a / b.y;
    c.z = a / b.z;
    c.w = a / b.w;
    return (c);
}
