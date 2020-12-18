/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuplesOps2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:06:09 by matraore          #+#    #+#             */
/*   Updated: 2020/11/12 03:31:40 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

double magnetudeVector(t_tuple vect)
{
    double mag;

    mag = sqrt((vect.x * vect.x) + (vect.y * vect.y) + (vect.z * vect.z));
    return (mag);
}

t_tuple normalizeVector(t_tuple vect)
{
    t_tuple unitVect;

    unitVect.x = vect.x / magnetudeVector(vect);
    unitVect.y = vect.y / magnetudeVector(vect);
    unitVect.z = vect.z / magnetudeVector(vect);
    unitVect.w = 0;
    return (unitVect);
}

//dot product
double scalarTuples(t_tuple a, t_tuple b)
{
    double c;

    c= a.x * b.x + a.y * b.y + a.z * b.z;
    return (c);
}

t_tuple crossTuples(t_tuple a, t_tuple b)
{
    return vector(a.y * b.z - a.z * b.y, 
        a.z * b.x - a.x * b.z, 
        a.x * b.y - a.y * b.x);
}
