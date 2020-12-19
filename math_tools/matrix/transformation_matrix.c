/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_matrix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 03:51:45 by matraore          #+#    #+#             */
/*   Updated: 2020/12/13 04:56:17 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat		*scaling(double x, double y, double z)
{
	t_mat	*mat;

	mat = matrix_identity(4);
	mat->entries[0][0] = x;
	mat->entries[1][1] = y;
	mat->entries[2][2] = z;
	return (mat);
}

t_mat		*rotation_x(double y)
{
	t_mat	*mat;

	mat = matrix_identity(4);
	mat->entries[1][1] = cos(y);
	mat->entries[1][2] = sin(y) * (-1);
	mat->entries[2][1] = sin(y);
	mat->entries[2][2] = cos(y);
	return (mat);
}

t_mat		*rotation_y(double y)
{
	t_mat	*mat;

	mat = matrix_identity(4);
	mat->entries[0][0] = cos(y);
	mat->entries[0][2] = sin(y);
	mat->entries[2][0] = sin(y) * (-1);
	mat->entries[2][2] = cos(y);
	return (mat);
}

t_mat		*rotation_z(double y)
{
	t_mat	*mat;

	mat = matrix_identity(4);
	mat->entries[0][0] = cos(y);
	mat->entries[0][1] = sin(y) * (-1);
	mat->entries[1][0] = sin(y);
	mat->entries[1][1] = cos(y);
	return (mat);
}
