/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:59:23 by ashih             #+#    #+#             */
/*   Updated: 2018/04/11 07:19:05 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			inc_light_x(t_master *m)
{
	if (m->light->type == POINT_LIGHT)
		m->light->pos[0] += LIGHT_POS_INC;
	else
		m->light->rot_x += LIGHT_ROT_INC;
}

void			dec_light_y(t_master *m)
{
	if (m->light->type == POINT_LIGHT)
		m->light->pos[1] -= LIGHT_POS_INC;
	else
		m->light->rot_y -= LIGHT_ROT_INC;
}

void			inc_light_y(t_master *m)
{
	if (m->light->type == POINT_LIGHT)
		m->light->pos[1] += LIGHT_POS_INC;
	else
		m->light->rot_y += LIGHT_ROT_INC;
}

void			dec_light_z(t_master *m)
{
	if (m->light->type == POINT_LIGHT)
		m->light->pos[2] -= LIGHT_POS_INC;
	else
		m->light->rot_z -= LIGHT_ROT_INC;
}

void			inc_light_z(t_master *m)
{
	if (m->light->type == POINT_LIGHT)
		m->light->pos[2] += LIGHT_POS_INC;
	else
		m->light->rot_z += LIGHT_ROT_INC;
}
