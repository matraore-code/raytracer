/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 05:40:26 by matraore          #+#    #+#             */
/*   Updated: 2020/12/18 23:27:24 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat			*create_matrix(int row, int col)
{
	t_mat		*mat;
	int			k;

	mat = tools_malloc(sizeof(t_mat));
	mat->d = tools_malloc(sizeof(double) * row * col);
	mat->row = row;
	mat->col = col;
	mat->entries = tools_malloc(sizeof(double *) * row);
	if (mat->entries == NULL || mat->d == NULL)
	{
		free(mat);
		return (NULL);
	}
	k = 0;
	while (k < row)
	{
		mat->entries[k] = mat->d + k * col;
		k++;
	}
	fill_matrix(mat, 0);
	return (mat);
}

void			destroy_matrix(t_mat *mat)
{
	free(mat->d);
	free(mat->entries);
	free(mat);
	mat = NULL;
}

void			set_cell_matrix(t_mat *mat, int x, int y, double val)
{
	double		*p;

	p = mat->d + y + x * mat->col;
	*p = val;
}

double			get_cell_matrix(t_mat *mat, int x, int y)
{
	double		*p;

	p = mat->d + x + y * mat->col;
	return (*p);
}

void			fill_matrix(t_mat *mat, double val)
{
	int			i;
	int			j;

	j = 0;
	while (j < mat->row)
	{
		i = 0;
		while (i < mat->col)
		{
			set_cell_matrix(mat, i, j, val);
			i++;
		}
		j++;
	}
}
