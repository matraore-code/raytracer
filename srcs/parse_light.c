/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 01:21:55 by ashih             #+#    #+#             */
/*   Updated: 2018/04/10 15:03:43 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** array[0] = LIGHT_POINT
** array[1] = name
** array[2] = position
*/

static int		parse_point_light_array(char **array, t_master *m)
{
	t_vect3		v;

	if (parse_vector(array[2], &v))
		return (ft_puterror("Invalid position", array[2], 1));
	return (add_light(&m->light_list, array[1], POINT_LIGHT, &v));
}

/*
** array[0] = LIGHT_DISTANT
** array[1] = name
** array[2] = direction, normalized
*/

static int		parse_distant_light_array(char **array, t_master *m)
{
	t_vect3		v;

	if (parse_vector(array[2], &v) || v_is_zero(&v))
		return (ft_puterror("Invalid direction", array[2], 1));
	v_normalize(&v);
	return (add_light(&m->light_list, array[1], DISTANT_LIGHT, &v));
}

int				parse_light_line(char *line, t_master *m)
{
	char		**array;
	int			error;

	error = 0;
	array = ft_strsplit(line, ';');
	if (ft_char_array_length(array) == 3)
	{
		if (ft_strequ(array[0], "LIGHT_POINT"))
			error = parse_point_light_array(array, m);
		else if (ft_strequ(array[0], "LIGHT_DISTANT"))
			error = parse_distant_light_array(array, m);
		else
			error = 1;
	}
	else
		error = ft_puterror(ERROR_NUM_TERMS, 0, 1);
	ft_char_array_del(array);
	return (error);
}
