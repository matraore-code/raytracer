/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:00:03 by matraore          #+#    #+#             */
/*   Updated: 2020/11/25 03:09:10 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "../utils/libft/libft.h"
#include "../utils/tools/tools.h"


typedef struct	s_tuples
{
	double x;
	double y;
	double z;
	double w;
}		t_tuple;

typedef struct	s_colorvec
{
	float red;
	float green;
	float blue;
}		t_color;

/* A tuple with w=1.0 is a point
** A tuple with w=0.0 is a vector
*/

t_tuple		create_tuple(double x, double y, double z);
t_tuple		point(t_tuple p);
t_tuple		vector(t_tuple p);
int		equal(double a, double b);
int		comparing_tuples(t_tuple a, t_tuple b);
double		scalar_tuples(t_tuple a, t_tuple b);
t_tuple		normalize_vector(t_tuple vect);
double		magnetude_vector(t_tuple vect);
t_tuple		cross_tuples(t_tuple a, t_tuple b);
t_tuple		sum_tuples(t_tuple a, t_tuple b);
t_tuple		sub_tuples(t_tuple a, t_tuple b);
t_tuple		multi_tuples(double a, t_tuple b);
t_tuple		div_tuples(double a, t_tuple b);

/**color implementation
 *
 **/ 

t_color		color(float red, float green, float blue);
t_color		adding_color(t_color c, t_color d);
t_color		sub_color(t_color c, t_color d);
t_color		multip_color(t_color c, t_color d);
t_color		scalar_color(float c, t_color d);
int		color_rgb_to_hex(t_color c);
#endif
