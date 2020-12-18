/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 20:16:53 by matraore          #+#    #+#             */
/*   Updated: 2020/12/18 21:00:43 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

typedef	struct	s_tuples	t_tuple;

struct	s_tuples
{
	double x;
	double y;
	double z;
	double w;
};

int			is_equal(double a, double b);

t_tuple		create_point(double x, double y, double z);
t_tuple		create_vector(double x, double y, double z);

#endif
