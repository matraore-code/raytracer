/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:38:28 by matraore          #+#    #+#             */
/*   Updated: 2020/11/12 03:07:31 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef _MATRICES_H
# define _MATRICES_H
#define PI 3.141593

#include "stdio.h"
#include "stdlib.h"
#include "../tuples/tuples.h"
#include "../utils/tools/tools.h"




typedef struct _matrice t_Smatrice;
typedef struct _matrice *t_matrice;

struct _matrice
{
    int n_rows;
    int n_columns;
    double *data;
    double **d;
};

t_matrice matrice (int n_lines, int n_colones);
void matrice_destroy (t_matrice* AA);
void set_cell(t_matrice A, int x, int y, double value);
double get_cell (t_matrice A, int x, int y);
t_matrice identity_matrix(void);
t_matrice matrix_clone (t_matrice M);
void fill_matrice (t_matrice A, double value);
void fill_matrice_with_increament(t_matrice A, double value);
int matrices_equal (t_matrice M1, t_matrice M2);
double minor (t_matrice M, int row, int column);
double cofactor (t_matrice M, int row, int column);



t_matrice matrix_multiply (t_matrice A, t_matrice B);

t_matrice matrix_multiply_by_scalar (t_matrice A, double s);

void transpose(t_matrice M);


void matrix_4x4_debug (t_matrice M);

void matrix_debug(t_matrice M);

double matrix_2x2_determinant (t_matrice M);
t_matrice submatrix (t_matrice M, int row, int column);

double matrix_3x3_determinant (t_matrice M);

double m_4x4_cofactor(t_matrice M, int row, int column);


double matrix_4x4_determinant (t_matrice M);

double determinant (t_matrice M);

t_matrice adjoint (t_matrice M);

int is_it_invertible (t_matrice M);

t_matrice inverse (t_matrice M);

t_matrice tup_to_matrix (t_tuple t);

t_tuple matrix_to_tup (t_matrice M);

t_tuple matrix_multiply_by_tuple (t_matrice M, t_tuple p);



t_matrice translation (int x, int y, int z);

t_matrice scaling (int x, int y, int z);

/*
** rotation around the x axis
*/
t_matrice rotation_x (double degree);

/*
**  rotation around the y axis 
*/

t_matrice rotation_y (double degree);

/*
**  rotation around the z axis 
*/

t_matrice rotation_z (double degree);

t_matrice shearing (int x_y, int x_z, int y_x, int y_z, int z_x, int z_y);
#endif