/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 03:13:43 by matraore          #+#    #+#             */
/*   Updated: 2020/12/13 03:18:26 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat		*mult_matr_scalar(t_mat *mat, double a)
{
	t_mat	*m;
	int		i;

	m = matrix_clone(mat);
	i = 0;
	printf("a = %.3f\n", a);
	while (i < mat->row * mat->col)
	{
		*(m->d + (i)) *= a;
		i++;
	}
	return (m);
}

t_mat		*submatrix(t_mat *mat, int row, int col)
{
	t_mat	*sub;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 0;
	sub = create_matrix(mat->row - 1, mat->col - 1);
	while (j < mat->row)
	{
		i = 0;
		while (i < mat->col)
		{
			if ((i != col) && (j != row) && (k < (mat->col * mat->row)))
				*(sub->d + (k++)) = get_cell_matrix(mat, i, j);
			i++;
		}
		j++;
	}
	return (sub);
}

double		minor_matrix(t_mat *mat, int row, int col)
{
	double	m;
	t_mat	*matr;

	m = 0;
	if (mat->col != 2 && mat->row != 2)
	{
		matr = submatrix(mat, row, col);
		m = determinant_2x2(matr);
		destroy_matrix(matr);
		return (m);
	}
	return (m);
}

double		determinant_2x2(t_mat *m)
{
	double	d;

	d = 0;
	if (m->col == 2 && m->row == 2)
	{
		d = ((m->entries[0][0] * m->entries[1][1]) -
				(m->entries[0][1] * m->entries[1][0]));
	}
	return (d);
}

double		cofactor_3x3(t_mat *mat, int row, int col)
{
	int		n;
	double	co;

	n = row + col;
	co = (minor_matrix(mat, row, col));
	if (n % 2 != 0)
		co *= -1;
	return (co);
}
