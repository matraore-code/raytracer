/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:59:23 by ashih             #+#    #+#             */
/*   Updated: 2018/04/11 07:19:27 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			dec_obj_phong_n(t_master *m)
{
	m->obj->phong_n -= PHONG_N_INC;
	CLAMP(m->obj->phong_n, PHONG_N_MIN, PHONG_N_MAX);
}

void			inc_obj_phong_n(t_master *m)
{
	m->obj->phong_n += PHONG_N_INC;
	CLAMP(m->obj->phong_n, PHONG_N_MIN, PHONG_N_MAX);
}

void			dec_obj_k(t_master *m)
{
	if (m->shift_down)
	{
		m->obj->k_specular -= K_SPECULAR_INC;
		CLAMP(m->obj->k_specular, 0.0, 1.0);
	}
	else
	{
		m->obj->k_diffuse -= K_DIFFUSE_INC;
		CLAMP(m->obj->k_diffuse, 0.0, 1.0);
	}
}

void			inc_obj_k(t_master *m)
{
	if (m->shift_down)
	{
		m->obj->k_specular += K_SPECULAR_INC;
		CLAMP(m->obj->k_specular, 0.0, 1.0);
	}
	else
	{
		m->obj->k_diffuse += K_DIFFUSE_INC;
		CLAMP(m->obj->k_diffuse, 0.0, 1.0);
	}
}

void			dec_obj_x(t_master *m)
{
	if (m->shift_down)
		m->obj->rot_x -= OBJ_ROT_INC;
	else
		m->obj->center[0] -= OBJ_POS_INC;
}
