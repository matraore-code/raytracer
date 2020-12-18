/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:41:55 by matraore          #+#    #+#             */
/*   Updated: 2020/12/18 20:50:22 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"
#include <math.h>

#define EPSILON 0.00001

int		is_equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	else
		return (0);
}
