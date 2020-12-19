/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 05:14:00 by matraore          #+#    #+#             */
/*   Updated: 2020/12/13 03:19:00 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

int			is_inversible(t_mat *mat)
{
	if (determinant_matrix(mat) != 0)
		return (1);
	return (0);
}

t_mat		*inverse_matrix(t_mat *mat)
{
	t_mat	*adj;
	t_mat	*inv;
	double	d;

	d = 1.0 / determinant_matrix(mat);
	printf("%.3f\n", d);
	if (is_inversible(mat) != 0)
	{
		adj = matrix_adjoint(mat);
		inv = mult_matr_scalar(adj, d);
		return (inv);
	}
	return (NULL);
}

double		cofactor_matrix(t_mat *mat, int row, int col)
{
	if (mat->row == 3 && mat->col == 3)
		return (cofactor_3x3(mat, row, col));
	if (mat->row == 4 && mat->col == 4)
		return (cofactor_4x4(mat, row, col));
	return (1337);
}

t_mat		*matrix_adjoint(t_mat *mat)
{
	t_mat	*adj;
	int		k;
	int		j;
	int		i;

	j = 0;
	k = 0;
	adj = matrix_clone(mat);
	while (j < mat->row)
	{
		i = 0;
		while (i < mat->col)
		{
			*(adj->d + (k++)) = cofactor_matrix(mat, j, i);
			i++;
		}
		j++;
	}
	transpose_matrix(adj);
	return (adj);
}
