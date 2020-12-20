/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 21:49:59 by ashih             #+#    #+#             */
/*   Updated: 2018/04/10 17:23:59 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		free_mlx_stuff(t_master *m)
{
	if (m->win)
		mlx_destroy_window(m->mlx, m->win);
	if (m->img)
		mlx_destroy_image(m->mlx, m->img);
	if (m->mlx)
	{
		ft_memdel((void **)&m->mlx->font[1]);
		ft_memdel((void **)&m->mlx->font);
		ft_memdel((void **)&m->mlx);
	}
}

static void		free_light(t_light *light)
{
	if (!light)
		return ;
	ft_strdel(&light->name);
	ft_memdel((void **)&light);
}

static void		free_obj(t_obj *obj)
{
	if (!obj)
		return ;
	ft_strdel(&obj->name);
	ft_memdel((void **)&obj);
}

int				free_all(t_master *m, char *message)
{
	free_mlx_stuff(m);
	ft_lstdel(&m->light_list, (void (*)(void *, size_t))free_light);
	ft_lstdel(&m->obj_list, (void (*)(void *, size_t))free_obj);
	if (message)
		ft_puterror(message, 0, 0);
	return (0);
}
