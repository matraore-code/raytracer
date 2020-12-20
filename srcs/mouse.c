/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 10:03:00 by ashih             #+#    #+#             */
/*   Updated: 2018/04/09 00:58:33 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** Key						Function
** Mouse LMB				Select object
*/

int			mouse_button_down(int button, int x, int y, t_master *m)
{
	t_ray	ray;

	if (button != LMB)
		return (0);
	init_ray(&ray, (double)x, (double)y, &m->cam);
	if (trace(&ray, m->obj_list))
	{
		m->obj = ray.hit_obj;
		print_info(m);
	}
	return (0);
}
