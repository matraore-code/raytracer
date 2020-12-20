/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 00:13:48 by ashih             #+#    #+#             */
/*   Updated: 2018/04/10 04:36:01 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			solve_quadratic(t_quadratic *q, double *t)
{
	double	discr;
	double	temp;

	discr = SQ(q->b) - 4.0 * q->a * q->c;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		q->x0 = -0.5 * q->b / q->a;
		q->x1 = q->x0;
	}
	else
	{
		temp = (q->b > 0.0) ? (q->b + sqrt(discr)) / -2.0 :
			(q->b - sqrt(discr)) / -2.0;
		q->x0 = temp / q->a;
		q->x1 = q->c / temp;
	}
	return (check_quadratic_results(q, t));
}

int			check_quadratic_results(t_quadratic *q, double *t)
{
	if (q->x0 > q->x1)
		SWAP(q->x0, q->x1, double);
	if (q->x0 < 0.0)
	{
		q->x0 = q->x1;
		if (q->x0 < 0.0)
			return (0);
	}
	*t = q->x0;
	return (1);
}
