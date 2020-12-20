/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:59:23 by ashih             #+#    #+#             */
/*   Updated: 2018/04/11 07:17:45 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			terminate(t_master *m)
{
	free_all(m, 0);
	exit(0);
}

void			dec_fov(t_master *m)
{
	m->cam.fov_h -= FOV_INC;
	m->cam.fov_v -= FOV_INC;
	CLAMP(m->cam.fov_h, FOV_MIN, FOV_MAX);
	CLAMP(m->cam.fov_v, FOV_MIN, FOV_MAX);
}

void			inc_fov(t_master *m)
{
	m->cam.fov_h += FOV_INC;
	m->cam.fov_v += FOV_INC;
	CLAMP(m->cam.fov_h, FOV_MIN, FOV_MAX);
	CLAMP(m->cam.fov_v, FOV_MIN, FOV_MAX);
}

void			dec_cam_x(t_master *m)
{
	if (m->shift_down)
		m->cam.rot_x -= CAM_ROT_INC;
	else
		m->cam.pos[0] -= CAM_POS_INC;
}

void			inc_cam_x(t_master *m)
{
	if (m->shift_down)
		m->cam.rot_x += CAM_ROT_INC;
	else
		m->cam.pos[0] += CAM_POS_INC;
}
