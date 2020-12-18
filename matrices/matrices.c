/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:38:18 by matraore          #+#    #+#             */
/*   Updated: 2020/11/11 05:27:03 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "matrices.h"

t_matrice matrice(int n_lines, int n_colones)
{
    t_matrice A;
    int r;

    A = tools_malloc(sizeof(struct _matrice));
    A->n_rows = n_lines;
    A->n_columns = n_colones;
    A->data = tools_malloc(sizeof(double) * A->n_rows * A->n_columns);
    A->d = malloc(sizeof(double *) * n_lines);
    r = 0;
    while (r < n_lines)
    {
        A->d[r] = A->data + r * A->n_columns;
        r++;
    }
    fill_matrice(A, 0);
    return (A);
}

void matrice_destroy(t_matrice *AA)
{
    t_matrice A;

    A = *AA;
    free(A->data);
    free(A->d);
    free(A);
    *AA = NULL;
}

void set_cell(t_matrice A, int x, int y, double value)
{
    double *ptr;

    ptr = A->data + x + y * A->n_columns;
    *ptr = value;
}

double get_cell(t_matrice A, int x, int y)
{
    double *ptr;

    ptr = A->data + x + y * A->n_columns;
    return (*ptr);
}

t_matrice matrix_clone(t_matrice M)
{
    t_matrice c;
    int k;

    k = 0;
    c = matrice(M->n_rows, M->n_columns);
    while (k < (M->n_columns * M->n_rows))
    {
        *(c->data + (k)) = *(M->data + (k));
        k++;
    }
    return (c);
}

void fill_matrice(t_matrice A, double value)
{
    int i;
    int j;

    j = 0;
    while (j < A->n_rows)
    {
        i = 0;
        while (i < A->n_columns)
        {
            set_cell(A, i, j, value);
            i++;
        }
        j++;
    }
}

void fill_matrice_with_increament(t_matrice A, double value)
{
    int i;
    int j;

    j = 0;
    while (j < A->n_rows)
    {
        i = 0;
        while (i < A->n_columns)
        {
            A->d[j][i] = value++;
            i++;
        }
        j++;
    }
}

int matrices_equal(t_matrice M1, t_matrice M2)
{
    double *ptr1;
    double *ptr2;
    int i;
    int j;

    if ((M1->n_columns != M2->n_columns) || (M1->n_rows != M2->n_rows))
        return 0;
    i = 0;
    j = 0;
    ptr1 = M1->data;
    ptr2 = M2->data;
    while (j < M1->n_rows)
    {
        i = 0;
        while (i < M1->n_columns)
        {
            if (d_equal(*ptr1, *ptr2) == 0)
                return 0;
            ptr1++;
            ptr2++;
            i++;
        }
        j++;
    }
    return 1;
}

double matrix_mutiply_aux(t_matrice A, t_matrice B, int i, int j)
{
    double s;
    int k;

    k = 0;
    s = 0; 
    while (k < A->n_columns)
    {
        s += A->d[j][k] * B->d[k][i];
        k++;
    }
    return (s);
}


t_matrice matrix_multiply(t_matrice A, t_matrice B)
{
    t_matrice M;
    int i;
    int j;

    j = 0;
    M = matrice(A->n_rows, B->n_columns);
    while (j < A->n_rows)
    {
        i = 0;
        while (i < B->n_columns)
        {
            M->d[j][i] = matrix_mutiply_aux (A, B, i, j);
            i++;
        }
        j++;
    }
    return (M);
}

t_matrice matrix_multiply_by_scalar(t_matrice M, double s)
{
    t_matrice c;
    int k;

    c = matrix_clone(M);
    k = 0;
    while (k < (M->n_columns * M->n_rows))
    {
        *(c->data + (k)) *= (s);
        k++;
    }
    return (c);
}

void transpose(t_matrice M)
{
    int i;
    int j;
    t_matrice tmp;

    tmp = matrix_clone(M);
    j = 0;
    while (j < M->n_rows)
    {
        i = 0;
        while (i < M->n_columns)
        {
            M->d[j][i] = tmp->d[i][j];
            i++;
        }
        j++;
    }
    matrice_destroy(&tmp);
}

void matrix_4x4_debug(t_matrice M)
{
    int i;
    int j;

    j = 0;
    printf("\n-----------------------------------------------\n");
    while (j < 4)
    {
        i = 0;
        printf(" | ");
        while (i < 4)
        {
            printf("%f", get_cell(M, i, j));
            printf(" | ");
            i++;
        }
        printf("\n-----------------------------------------------\n");
        j++;
    }
}

// void matrix_debug(t_matrice M)
// {
//     int i;
//     int j;

//     j = 0;
//     printf("\n-----------------------------------------------\n");
//     while (j < M->n_rows)
//     {
//         i = 0;
//         printf(" | ");
//         while (i < M->n_columns)
//         {
//             printf("%f", get_cell(M, i, j));
//             //printf("%f", M->d[j][i]);
//             printf(" | ");
//             i++;
//         }
//         printf("\n-----------------------------------------------\n");
//         j++;
//     }
// }

t_matrice identity_matrix(void)
{
    t_matrice M;
    int i;

    M = matrice(4, 4);
    i = 0;
    while (i < 4)
    {
        set_cell(M, i, i, 1);
        i++;
    }
    return M;
}

double matrix_2x2_determinant(t_matrice M)
{
    if (M->n_columns != 2 || M->n_rows != 2)
    {
        printf("non valid matrix dimension");
        return -42.42;
    }

    return (M->d[0][0] * M->d[1][1]) - (M->d[0][1] * M->d[1][0]);
}

t_matrice submatrix(t_matrice M, int row, int column)
{
    t_matrice sub_m;
    int i;
    int j;
    int k;

    j = 0;
    k = 0;
    sub_m = matrice(M->n_rows - 1, M->n_columns - 1);
    while (j < M->n_rows)
    {
        i = 0;
        while (i < M->n_columns)
        {
            if ((i != column) && (j != row) && (k < (M->n_columns * M->n_rows)))
                *(sub_m->data + (k++)) = get_cell(M, i, j);
            i++;
        }
        j++;
    }
    return (sub_m);
}

double minor(t_matrice M, int row, int column)
{
    double n;
    t_matrice A;

    n = 0;
    if (M->n_columns != 2 && M->n_rows != 2)
    {
        A = submatrix(M, row, column);
        n = matrix_2x2_determinant(A);
        matrice_destroy(&A);
        return (n);
    }

    return (n);
}

double cofactor(t_matrice M, int row, int column)
{
    int check_parity;
    double r;

    check_parity = row + column;
    r = (minor(M, row, column));
    if (check_parity % 2 != 0)
        r *= -1;
    return (r);
}

double matrix_3x3_determinant(t_matrice M)
{
    double n;

    n = (M->d[0][0] * cofactor(M, 0, 0));
    n += (M->d[0][1] * cofactor(M, 0, 1));
    n += (M->d[0][2] * cofactor(M, 0, 2));

    return (n);
}
double matrix_3x3_determinant_and_destroyM(t_matrice M)
{
    double n = matrix_3x3_determinant(M);
    matrice_destroy(&M);
    return (n);
}

double m_4x4_cofactor(t_matrice M, int row, int column)
{
    int check_parity;
    double r;

    check_parity = row + column;
    r = matrix_3x3_determinant_and_destroyM(submatrix(M, row, column));
    if (check_parity % 2 != 0)
        r *= -1;
    return (r);
}

double matrix_4x4_determinant(t_matrice M)
{
    double n;

    n = (M->d[0][0] * m_4x4_cofactor(M, 0, 0));
    n += (M->d[0][1] * m_4x4_cofactor(M, 0, 1));
    n += (M->d[0][2] * m_4x4_cofactor(M, 0, 2));
    n += (M->d[0][3] * m_4x4_cofactor(M, 0, 3));

    return (n);
}

double determinant(t_matrice M)
{
    if (M->n_columns == 2 && M->n_rows == 2)
        return matrix_2x2_determinant(M);
    else if (M->n_columns == 3 && M->n_rows == 3)
        return matrix_3x3_determinant(M);
    else if (M->n_columns == 4 && M->n_rows == 4)
        return matrix_4x4_determinant(M);
    else
        return 0;
}

t_matrice adjoint(t_matrice M)
{
    int k;
    int i;
    int j;
    t_matrice adj;

    j = 0;
    k = 0;
    adj = matrix_clone(M);
    while (j < M->n_rows)
    {
        i = 0;
        while (i < M->n_columns)
        {
            *(adj->data + (k++)) = m_4x4_cofactor(M, j, i);
            i++;
        }
        j++;
    }
    transpose(adj);
    return (adj);
}

int is_it_invertible(t_matrice M)
{
    if (determinant(M))
        return 1;
    else
        return 0;
}

t_matrice inverse(t_matrice M)
{
    t_matrice adj;
    t_matrice inv;

    if (is_it_invertible(M) != 0 )
    {
        adj = adjoint(M);
        inv = matrix_multiply_by_scalar(adj, 1.0 / determinant(M));
        return (inv);
    }
    printf("la matrix n'est pas reversible");
    return NULL;
}

t_matrice tup_to_matrix (t_tuple t)
{
    t_matrice m;

    m = matrice (4, 1);
    m->d[0][0] = t.x;
    m->d[1][0] = t.y;
    m->d[2][0] = t.z;
    m->d[3][0] = t.w;
    return (m);
}

t_tuple matrix_to_tup (t_matrice M)
{
    t_tuple t;

    t = create_tuple(M->d[0][0], M->d[1][0], M->d[2][0], M->d[3][0]);
    return (t);
}

t_tuple matrix_multiply_by_tuple (t_matrice M, t_tuple p)
{
    t_tuple t;
    t_matrice tmp;
    t_matrice r;

    tmp = tup_to_matrix (p);
    r = matrix_multiply (M, tmp);
    matrice_destroy (&tmp);
    t = matrix_to_tup (r);
    matrice_destroy (&r);
    return (t);
}

t_tuple chaining_transformation (t_tuple pt, t_matrice A, t_matrice B, t_matrice C)
{
    t_matrice T;
    t_matrice P;

    T = matrix_multiply(B, A);
    P = matrix_multiply(C, T); 
    return (matrix_multiply_by_tuple(P, pt));
}


// int main()
// {
//     t_matrice matr;
//     t_matrice matr1;
//     t_matrice matr2;
//     t_tuple k;
//     t_tuple c;
//     t_tuple d;
//     t_tuple e;
    
//     //matr = scaling(-1, 1, 1);
//     matr = shearing(0, 1, 0, 0, 0, 0);
//     matr1 = inverse(rotation_x(PI / 4));
//     matr2 = rotation_x(PI / 2);
//     k = matrix_multiply_by_tuple(matr1, point(0, 1, 0));
//     c = matrix_multiply_by_tuple(matr2, point(0, 1, 0));
//     d = matrix_multiply_by_tuple(matr, point(2, 3, 4));
//     e = chaining_transformation(point(1, 0, 1), rotation_x(PI / 2), scaling(5, 5, 5), translation(10 , 5, 7));
    
//     printf(" k(%.2f %.2f %.2f %.2f)\n", k.x, k.y, k.z, k.w);
//     printf(" c(%.2f %.2f %.2f %.2f)\n", c.x, c.y, c.z, c.w);
//     printf(" d(%.2f %.2f %.2f %.2f)\n", d.x, d.y, d.z, d.w);
//     printf(" e(%.2f %.2f %.2f %.2f)", e.x, e.y, e.z, e.w);
//     return 0;
// }