/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 08:07:44 by ashih             #+#    #+#             */
/*   Updated: 2018/04/11 07:55:49 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static	void		mult_matrix(t_matrix *m1, t_matrix *m2, t_matrix *r)
{
	t_vect3			m2_c0;
	t_vect3			m2_c1;
	t_vect3			m2_c2;

	v_init(&m2_c0, m2->r0[0], m2->r1[0], m2->r2[0]);
	v_init(&m2_c1, m2->r0[1], m2->r1[1], m2->r2[1]);
	v_init(&m2_c2, m2->r0[2], m2->r1[2], m2->r2[2]);
	r->r0[0] = v_dot(&m1->r0, &m2_c0);
	r->r0[1] = v_dot(&m1->r0, &m2_c1);
	r->r0[2] = v_dot(&m1->r0, &m2_c2);
	r->r1[0] = v_dot(&m1->r1, &m2_c0);
	r->r1[1] = v_dot(&m1->r1, &m2_c1);
	r->r1[2] = v_dot(&m1->r1, &m2_c2);
	r->r2[0] = v_dot(&m1->r2, &m2_c0);
	r->r2[1] = v_dot(&m1->r2, &m2_c1);
	r->r2[2] = v_dot(&m1->r2, &m2_c2);
}

static void			mult_rot_x_matrix(double rot_x, t_matrix *m2, t_matrix *r)
{
	t_matrix		rot_x_matrix;
	double			rad;

	ft_bzero(&rot_x_matrix, sizeof(t_matrix));
	rad = DEG_TO_RAD(rot_x);
	rot_x_matrix.r0[0] = 1.0;
	rot_x_matrix.r1[1] = cos(rad);
	rot_x_matrix.r1[2] = sin(rad) * -1.0;
	rot_x_matrix.r2[1] = sin(rad);
	rot_x_matrix.r2[2] = cos(rad);
	mult_matrix(&rot_x_matrix, m2, r);
}

static void			mult_rot_y_matrix(double rot_y, t_matrix *m2, t_matrix *r)
{
	t_matrix		rot_y_matrix;
	double			rad;

	ft_bzero(&rot_y_matrix, sizeof(t_matrix));
	rad = DEG_TO_RAD(rot_y);
	rot_y_matrix.r0[0] = cos(rad);
	rot_y_matrix.r0[2] = sin(rad);
	rot_y_matrix.r1[1] = 1.0;
	rot_y_matrix.r2[0] = sin(rad) * -1.0;
	rot_y_matrix.r2[2] = cos(rad);
	mult_matrix(&rot_y_matrix, m2, r);
}

static void			mult_rot_z_matrix(double rot_z, t_matrix *m2, t_matrix *r)
{
	t_matrix		rot_z_matrix;
	double			rad;

	ft_bzero(&rot_z_matrix, sizeof(t_matrix));
	rad = DEG_TO_RAD(rot_z);
	rot_z_matrix.r0[0] = cos(rad);
	rot_z_matrix.r0[1] = sin(rad) * -1.0;
	rot_z_matrix.r1[0] = sin(rad);
	rot_z_matrix.r1[1] = cos(rad);
	rot_z_matrix.r2[2] = 1.0;
	mult_matrix(&rot_z_matrix, m2, r);
}

void				init_rot_matrix(t_matrix *m, double rot_x, double rot_y,
	double rot_z)
{
	ft_bzero(m, sizeof(t_matrix));
	m->r0[0] = 1.0;
	m->r1[1] = 1.0;
	m->r2[2] = 1.0;
	mult_rot_x_matrix(rot_x, m, m);
	mult_rot_y_matrix(rot_y, m, m);
	mult_rot_z_matrix(rot_z, m, m);
}
