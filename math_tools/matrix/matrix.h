/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 05:37:53 by matraore          #+#    #+#             */
/*   Updated: 2020/12/18 23:26:59 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include "../tuples/tuples.h"
# include "../tools/tools.h"
# include <math.h>

typedef	struct	s_matrix
{
	int			row;
	int			col;
	double		*d;
	double		**entries;
}				t_mat;

t_mat			*create_matrix(int row, int col);
void			destroy_matrix(t_mat *mat);
void			set_cell_matrix(t_mat *mat, int x, int y, double val);
double			get_cell_matrix(t_mat *mat, int x, int y);
void			fill_matrix(t_mat *mat, double val);
t_mat			*matrix_clone(t_mat *mat);
void			transpose_matrix(t_mat *mat);
t_mat			*matrix_identity(int i);
double			mutipl_tools(t_mat *mat1, t_mat *mat2, int x, int y);
t_mat			*multi_matrix(t_mat *mat1, t_mat *mat2);
t_mat			*mult_matr_scalar(t_mat *mat, double a);
t_mat			*submatrix(t_mat *mat, int row, int col);
double			minor_matrix(t_mat *mat, int row, int col);
double			determinant_2x2(t_mat *mat);
double			cofactor_3x3(t_mat *mat, int row, int col);
double			cofactor_matrix(t_mat *mat, int row, int col);
double			determinant_3x3(t_mat *mat);
double			deter_free_mat(t_mat *mat);
double			cofactor_4x4(t_mat *mat, int row, int col);
double			determinant_4x4(t_mat *mat);
double			determinant_matrix(t_mat *mat);
int				is_inversible(t_mat *mat);
t_mat			*inverse_matrix(t_mat *mat);
t_mat			*matrix_adjoint(t_mat *mat);
t_mat			*tuple_to_matrix(t_tuple p);
t_tuple			matrix_to_tuple(t_mat *mat);
t_tuple			matrix_x_tuple(t_mat *mat, t_tuple p);
t_tuple			transformatiion(t_tuple pt, t_mat a, t_mat b, t_mat c);
t_mat			*translation(double x, double y, double z);
t_mat			*rotation_x(double y);
t_mat			*rotation_y(double y);
t_mat			*rotation_z(double y);

#endif
