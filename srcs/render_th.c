/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_th.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:01:42 by ashih             #+#    #+#             */
/*   Updated: 2018/04/10 04:51:43 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void			render_th_0(t_master *m)
{
	t_ray			ray;
	int				x;
	int				y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			init_ray(&ray, (double)x, (double)y, &m->cam);
			raycast(&ray, m->obj_list, m->light_list);
			draw_dot(x, y, &ray.final_color, m);
			x += 4;
		}
		y++;
	}
}

static void			render_th_1(t_master *m)
{
	t_ray			ray;
	int				x;
	int				y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 1;
		while (x < WIN_WIDTH)
		{
			init_ray(&ray, (double)x, (double)y, &m->cam);
			raycast(&ray, m->obj_list, m->light_list);
			draw_dot(x, y, &ray.final_color, m);
			x += 4;
		}
		y++;
	}
}

static void			render_th_2(t_master *m)
{
	t_ray			ray;
	int				x;
	int				y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 2;
		while (x < WIN_WIDTH)
		{
			init_ray(&ray, (double)x, (double)y, &m->cam);
			raycast(&ray, m->obj_list, m->light_list);
			draw_dot(x, y, &ray.final_color, m);
			x += 4;
		}
		y++;
	}
}

static void			render_th_3(t_master *m)
{
	t_ray			ray;
	int				x;
	int				y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 3;
		while (x < WIN_WIDTH)
		{
			init_ray(&ray, (double)x, (double)y, &m->cam);
			raycast(&ray, m->obj_list, m->light_list);
			draw_dot(x, y, &ray.final_color, m);
			x += 4;
		}
		y++;
	}
}

void				render_th_master(t_master *m)
{
	static void		(*th_func[THREAD_COUNT])(t_master *) = {render_th_0,
		render_th_1, render_th_2, render_th_3};
	pthread_t		threads[THREAD_COUNT];
	mach_port_t		ports[THREAD_COUNT];
	int				affinity[THREAD_COUNT];
	int				i;

	i = -1;
	while (++i < 4)
	{
		pthread_create_suspended_np(threads + i, 0,
			(void *(*)(void *))th_func[i], m);
		ports[i] = pthread_mach_thread_np(threads[i]);
		affinity[i] = i;
		thread_policy_set(ports[i], THREAD_AFFINITY_POLICY, &affinity[i], 1);
		thread_resume(ports[i]);
	}
	i = -1;
	while (++i < 4)
		pthread_join(threads[i], 0);
}
