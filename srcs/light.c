/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 23:10:42 by ashih             #+#    #+#             */
/*   Updated: 2018/04/11 07:20:35 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				light_count(t_list *light_list)
{
	int			count;
	t_light		*light;

	count = 0;
	while (light_list)
	{
		light = light_list->content;
		if (light->on_state)
			count++;
		light_list = light_list->next;
	}
	return (count);
}

int				add_light(t_list **light_list, char *name,
	enum e_light_type type, t_vect3 *v)
{
	t_light		*light;

	if (!(light = ft_memalloc(sizeof(t_light))))
		return (ft_puterror(ERROR_MEMORY, 0, 1));
	if (!(light->name = ft_strdup(name)))
	{
		ft_memdel((void **)&light);
		return (ft_puterror(ERROR_MEMORY, 0, 1));
	}
	light->type = type;
	light->intensity = 1.0;
	set_color(&light->color, 0xFFFFFF);
	light->on_state = 1;
	if (type == POINT_LIGHT)
		ft_memcpy(&light->pos, v, sizeof(t_vect3));
	else
		ft_memcpy(&light->dir_0, v, sizeof(t_vect3));
	ft_lst_add_last(light_list, ft_lst_new_ref(light, sizeof(t_light)));
	return (0);
}

static void		print_light(t_light *light, t_light *selected)
{
	ft_printf(light->on_state ? "{green}[ON] " : "{red}[OFF] ");
	if (light == selected)
		ft_printf("{yellow}{bold}%s{reset}:", light->name);
	else
		ft_printf("{yellow}%s{reset}:", light->name);
	ft_printf("\tintensity = %.3f,", light->intensity);
	if (light->type == POINT_LIGHT)
		ft_printf("\tpos.x = %.3f\tpos.y = %.3f\tpos.z = %.3f\n",
			light->pos[0], light->pos[1], light->pos[2]);
	else
		ft_printf("\tdir.x = %.3f\tdir.y = %.3f\tdir.z = %.3f\n",
			light->dir[0], light->dir[1], light->dir[2]);
}

void			print_all_lights(t_list *light_list, t_light *selected)
{
	while (light_list)
	{
		print_light(light_list->content, selected);
		ft_printf("\n");
		light_list = light_list->next;
	}
}
