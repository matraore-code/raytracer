/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:59:23 by ashih             #+#    #+#             */
/*   Updated: 2018/04/11 07:19:51 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			inc_obj_x(t_master *m)
{
	if (m->shift_down)
		m->obj->rot_x += OBJ_ROT_INC;
	else
		m->obj->center[0] += OBJ_POS_INC;
}

void			dec_obj_y(t_master *m)
{
	if (m->shift_down)
		m->obj->rot_y -= OBJ_ROT_INC;
	else
		m->obj->center[1] -= OBJ_POS_INC;
}

void			inc_obj_y(t_master *m)
{
	if (m->shift_down)
		m->obj->rot_y += OBJ_ROT_INC;
	else
		m->obj->center[1] += OBJ_POS_INC;
}

void			dec_obj_z(t_master *m)
{
	if (m->shift_down)
		m->obj->rot_z -= OBJ_ROT_INC;
	else
		m->obj->center[2] -= OBJ_POS_INC;
}

void			inc_obj_z(t_master *m)
{
	if (m->shift_down)
		m->obj->rot_z += OBJ_ROT_INC;
	else
		m->obj->center[2] += OBJ_POS_INC;
}
