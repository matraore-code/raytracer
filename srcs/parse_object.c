/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 01:21:55 by ashih             #+#    #+#             */
/*   Updated: 2018/04/10 04:52:17 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** array[0] = OBJECT_SPHERE
** .
** .
** .
** array[6] = center
** array[7] = radius > 0.0
*/

int			parse_sphere_array(char **array, t_master *m)
{
	t_obj	*obj;
	int		error;

	error = 0;
	if (ft_char_array_length(array) != 8)
		return (ft_puterror(ERROR_NUM_TERMS, 0, 1));
	if (!(obj = ft_memalloc(sizeof(t_obj))))
		return (ft_puterror(ERROR_MEMORY, 0, 1));
	if (parse_any_obj_array(array, obj))
		error = 1;
	if (parse_vector(array[6], &obj->center))
		error = ft_puterror("Invalid center", array[6], 1);
	if ((obj->radius = ft_atodbl(array[7])) <= 0.0)
		error = ft_puterror("Invalid radius", array[7], 1);
	obj->type = SPHERE_OBJ;
	obj->intersect = sphere_intersect;
	ft_lst_add_last(&m->obj_list, ft_lst_new_ref(obj, sizeof(t_obj)));
	return (error);
}

/*
** array[0] = OBJECT_PLANE
** .
** .
** .
** array[6] = center
** array[7] = normal, normalized
*/

int			parse_plane_array(char **array, t_master *m)
{
	t_obj	*obj;
	int		error;

	error = 0;
	if (ft_char_array_length(array) != 8)
		return (ft_puterror(ERROR_NUM_TERMS, 0, 1));
	if (!(obj = ft_memalloc(sizeof(t_obj))))
		return (ft_puterror(ERROR_MEMORY, 0, 1));
	if (parse_any_obj_array(array, obj))
		error = 1;
	if (parse_vector(array[6], &obj->center))
		error = ft_puterror("Invalid center", array[6], 1);
	if (parse_vector(array[7], &obj->normal_0) || v_is_zero(&obj->normal_0))
		error = ft_puterror("Invalid normal", array[7], 1);
	v_normalize(&obj->normal_0);
	obj->type = PLANE_OBJ;
	obj->intersect = plane_intersect;
	ft_lst_add_last(&m->obj_list, ft_lst_new_ref(obj, sizeof(t_obj)));
	return (error);
}

/*
** array[0] = OBJECT_DISK
** .
** .
** .
** array[6] = center
** array[7] = normal, normalized
** array[8] = radius > 0.0
*/

int			parse_disk_array(char **array, t_master *m)
{
	t_obj	*obj;
	int		error;

	error = 0;
	if (ft_char_array_length(array) != 9)
		return (ft_puterror(ERROR_NUM_TERMS, 0, 1));
	if (!(obj = ft_memalloc(sizeof(t_obj))))
		return (ft_puterror(ERROR_MEMORY, 0, 1));
	if (parse_any_obj_array(array, obj))
		error = 1;
	if (parse_vector(array[6], &obj->center))
		error = ft_puterror("Invalid center", array[6], 1);
	if (parse_vector(array[7], &obj->normal_0) || v_is_zero(&obj->normal_0))
		error = ft_puterror("Invalid normal", array[7], 1);
	v_normalize(&obj->normal_0);
	if ((obj->radius = ft_atodbl(array[8])) <= 0.0)
		error = ft_puterror("Invalid radius", array[8], 1);
	obj->type = DISK_OBJ;
	obj->intersect = disk_intersect;
	ft_lst_add_last(&m->obj_list, ft_lst_new_ref(obj, sizeof(t_obj)));
	return (error);
}

/*
** array[0] = OBJECT_CYLINDER
** .
** .
** .
** array[6] = center
** array[7] = direction, normalized
** array[8] = radius > 0.0
*/

int			parse_cylinder_array(char **array, t_master *m)
{
	t_obj	*obj;
	int		error;

	error = 0;
	if (ft_char_array_length(array) != 9)
		return (ft_puterror(ERROR_NUM_TERMS, 0, 1));
	if (!(obj = ft_memalloc(sizeof(t_obj))))
		return (ft_puterror(ERROR_MEMORY, 0, 1));
	if (parse_any_obj_array(array, obj))
		error = 1;
	if (parse_vector(array[6], &obj->center))
		error = ft_puterror("Invalid center", array[6], 1);
	if (parse_vector(array[7], &obj->dir_0) || v_is_zero(&obj->dir_0))
		error = ft_puterror("Invalid direction", array[7], 1);
	v_normalize(&obj->dir_0);
	if ((obj->radius = ft_atodbl(array[8])) <= 0.0)
		error = ft_puterror("Invalid radius", array[8], 1);
	obj->type = CYLINDER_OBJ;
	obj->intersect = cylinder_intersect;
	ft_lst_add_last(&m->obj_list, ft_lst_new_ref(obj, sizeof(t_obj)));
	return (error);
}

/*
** array[0] = OBJECT_CONE
** .
** .
** .
** array[6] = center
** array[7] = direction, normalized
** array[8] = 0 < half_angle < 90
*/

int			parse_cone_array(char **array, t_master *m)
{
	t_obj	*obj;
	int		error;

	error = 0;
	if (ft_char_array_length(array) != 9)
		return (ft_puterror(ERROR_NUM_TERMS, 0, 1));
	if (!(obj = ft_memalloc(sizeof(t_obj))))
		return (ft_puterror(ERROR_MEMORY, 0, 1));
	if (parse_any_obj_array(array, obj))
		error = 1;
	if (parse_vector(array[6], &obj->center))
		error = ft_puterror("Invalid center", array[6], 1);
	if (parse_vector(array[7], &obj->dir_0) || v_is_zero(&obj->dir_0))
		error = ft_puterror("Invalid direction", array[7], 1);
	v_normalize(&obj->dir_0);
	obj->half_angle = ft_atodbl(array[8]);
	if (!(0.0 < obj->half_angle && obj->half_angle < 90.0))
		error = ft_puterror("Invalid half_angle", array[8], 1);
	obj->type = CONE_OBJ;
	obj->intersect = cone_intersect;
	ft_lst_add_last(&m->obj_list, ft_lst_new_ref(obj, sizeof(t_obj)));
	return (error);
}
