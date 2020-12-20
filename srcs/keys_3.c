/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:59:23 by ashih             #+#    #+#             */
/*   Updated: 2018/04/11 07:18:18 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			dec_cam_y(t_master *m)
{
	if (m->shift_down)
		m->cam.rot_y -= CAM_ROT_INC;
	else
		m->cam.pos[1] -= CAM_POS_INC;
}

void			inc_cam_y(t_master *m)
{
	if (m->shift_down)
		m->cam.rot_y += CAM_ROT_INC;
	else
		m->cam.pos[1] += CAM_POS_INC;
}

void			dec_cam_z(t_master *m)
{
	if (m->shift_down)
		m->cam.rot_z -= CAM_ROT_INC;
	else
		m->cam.pos[2] -= CAM_POS_INC;
}

void			inc_cam_z(t_master *m)
{
	if (m->shift_down)
		m->cam.rot_z += CAM_ROT_INC;
	else
		m->cam.pos[2] += CAM_POS_INC;
}
