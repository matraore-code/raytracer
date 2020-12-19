/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 00:52:53 by matraore          #+#    #+#             */
/*   Updated: 2020/12/13 05:04:01 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat			*matrix_clone(t_mat *mat)
{
	t_mat		*m;
	int			a;

	a = 0;
	m = create_matrix(mat->row, mat->col);
	while (a < mat->row * mat->col)
	{
		*(m->d + (a)) = *(mat->d + (a));
		a++;
	}
	return (m);
}

void			transpose_matrix(t_mat *mat)
{
	int			i;
	int			j;
	t_mat		*tmp;

	tmp = matrix_clone(mat);
	j = 0;
	while (j < mat->row)
	{
		i = 0;
		while (i < mat->col)
		{
			mat->entries[j][i] = tmp->entries[i][j];
			i++;
		}
		j++;
	}
	destroy_matrix(tmp);
}

t_mat			*matrix_identity(int i)
{
	t_mat		*mat;
	int			k;

	if (i < 2)
		return (NULL);
	mat = create_matrix(i, i);
	k = 0;
	while (k < i)
	{
		set_cell_matrix(mat, k, k, 1);
		k++;
	}
	return (mat);
}

double			mutipl_tools(t_mat *mat1, t_mat *mat2, int x, int y)
{
	double		m;
	int			i;

	m = 0;
	i = 0;
	while (i < mat1->col)
	{
		m += mat1->entries[y][i] * mat2->entries[i][x];
		i++;
	}
	return (m);
}

t_mat			*multi_matrix(t_mat *mat1, t_mat *mat2)
{
	t_mat		*m;
	int			j;
	int			i;

	j = 0;
	m = create_matrix(mat1->row, mat2->col);
	while (j < mat1->row)
	{
		i = 0;
		while (i < mat2->col)
		{
			m->entries[j][i] = mutipl_tools(mat1, mat2, i, j);
			i++;
		}
		j++;
	}
	return (m);
}
