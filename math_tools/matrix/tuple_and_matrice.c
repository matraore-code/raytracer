/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_and_matrice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 05:40:08 by matraore          #+#    #+#             */
/*   Updated: 2020/12/18 23:27:09 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat		*tuple_to_matrix(t_tuple p)
{
	t_mat	*mat;

	mat = create_matrix(4, 1);
	mat->entries[0][0] = p.x;
	mat->entries[1][0] = p.y;
	mat->entries[2][0] = p.z;
	mat->entries[3][0] = p.w;
	return (mat);
}

t_tuple		matrix_to_tuple(t_mat *mat)
{
	t_tuple	p;

	p = create_tuple(mat->entries[0][0], mat->entries[1][0],
			mat->entries[2][0]);
	p.w = mat->entries[3][0];
	return (p);
}

t_tuple		matrix_x_tuple(t_mat *mat, t_tuple p)
{
	t_tuple	v;
	t_mat	*tmp;
	t_mat	*m;

	tmp = tuple_to_matrix(p);
	m = multi_matrix(mat, tmp);
	destroy_matrix(tmp);
	v = matrix_to_tuple(m);
	destroy_matrix(m);
	return (v);
}

t_tuple		transformation(t_tuple pt, t_mat *a, t_mat *b, t_mat *c)
{
	t_tuple	tuple;
	t_mat	*t;
	t_mat	*p;

	t = multi_matrix(b, a);
	p = multi_matrix(c, t);
	tuple = matrix_x_tuple(p, pt);
	return (tuple);
}

t_mat		*translation(double x, double y, double z)
{
	t_mat	*mat;

	mat = matrix_identity(4);
	mat->entries[0][3] = x;
	mat->entries[1][3] = y;
	mat->entries[2][3] = z;
	return (mat);
}
