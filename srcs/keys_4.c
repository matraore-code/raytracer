/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:59:23 by ashih             #+#    #+#             */
/*   Updated: 2018/04/11 07:18:48 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			select_next_light(t_master *m)
{
	m->light_index = (m->light_index + 1) % ft_lst_size(m->light_list);
	m->light = ft_lst_at(m->light_list, m->light_index);
}

void			toggle_light(t_master *m)
{
	m->light->on_state = !m->light->on_state;
}

void			dec_light_intensity(t_master *m)
{
	m->light->intensity -= LIGHT_INTENSITY_INC;
	CLAMP(m->light->intensity, 0.0, 1.0);
}

void			inc_light_intensity(t_master *m)
{
	m->light->intensity += LIGHT_INTENSITY_INC;
	CLAMP(m->light->intensity, 0.0, 1.0);
}

void			dec_light_x(t_master *m)
{
	if (m->light->type == POINT_LIGHT)
		m->light->pos[0] -= LIGHT_POS_INC;
	else
		m->light->rot_x -= LIGHT_ROT_INC;
}
