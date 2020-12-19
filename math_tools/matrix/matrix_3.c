/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:28:40 by matraore          #+#    #+#             */
/*   Updated: 2020/12/12 23:56:25 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double		determinant_3x3(t_mat *mat)
{
	double	d;

	d = (mat->entries[0][0] * cofactor_matrix(mat, 0, 0));
	d += (mat->entries[0][1] * cofactor_matrix(mat, 0, 1));
	d += (mat->entries[0][2] * cofactor_matrix(mat, 0, 2));
	return (d);
}

double		deter_free_mat(t_mat *mat)
{
	double	d;

	d = determinant_3x3(mat);
	destroy_matrix(mat);
	return (d);
}

double		cofactor_4x4(t_mat *mat, int row, int col)
{
	int		n;
	double	d;

	n = row + col;
	d = deter_free_mat(submatrix(mat, row, col));
	if (n % 2 != 0)
		d *= -1;
	return (d);
}

double		determinant_4x4(t_mat *mat)
{
	double	d;

	d = (mat->entries[0][0] * cofactor_4x4(mat, 0, 0));
	d += (mat->entries[0][1] * cofactor_4x4(mat, 0, 1));
	d += (mat->entries[0][2] * cofactor_4x4(mat, 0, 2));
	d += (mat->entries[0][3] * cofactor_4x4(mat, 0, 3));
	return (d);
}

double		determinant_matrix(t_mat *mat)
{
	if (mat->col == 2 && mat->row == 2)
		return (determinant_2x2(mat));
	if (mat->col == 3 && mat->row == 3)
		return (determinant_3x3(mat));
	if (mat->col == 4 && mat->row == 4)
		return (determinant_4x4(mat));
	return (0);
}
