

#include "rtv1.h"

int				parse_vector(char *str, t_vect3 *v)
{
	char		**array;
	int			error;

	error = 0;
	array = ft_strsplit(str, ',');
	if (ft_char_array_length(array) != 3)
	{
		error = 1;
	}
	else
	{
		(*v)[0] = ft_atodbl(array[0]);
		(*v)[1] = ft_atodbl(array[1]);
		(*v)[2] = ft_atodbl(array[2]);
	}
	ft_char_array_del(array);
	return (error);
}

/*
** array[0] = OBJECT_TYPE
** array[1] = name
** array[2] = color
** array[3] = k_diffuse
** array[4] = k_specular
** array[5] = phong_n
** array[...] = // depends on OBJECT_TYPE
*/

int				parse_any_obj_array(char **array, t_obj *obj)
{
	int			color;
	int			error;

	error = 0;
	if (!(obj->name = ft_strdup(array[1])))
		return (ft_puterror(ERROR_MEMORY, 0, 1));
	if (ft_hex_to_int_check(array[2], &color))
		error = ft_puterror(ERROR_COLOR, array[2], 1);
	set_color(&obj->color, color);
	obj->k_diffuse = ft_atodbl(array[3]);
	if (!IN_RANGE(obj->k_diffuse, 0.0, 1.0))
		error = ft_puterror("Invalid k_diffuse", array[3], 1);
	obj->k_specular = ft_atodbl(array[4]);
	if (!IN_RANGE(obj->k_specular, 0.0, 1.0))
		error = ft_puterror("Invalid k_specular", array[4], 1);
	obj->phong_n = ft_atodbl(array[5]);
	if (!IN_RANGE(obj->phong_n, PHONG_N_MIN, PHONG_N_MAX))
		error = ft_puterror("Invalid phong_n", array[5], 1);
	return (error);
}

static int		parse_obj_line(char *line, t_master *m)
{
	char		**array;
	int			error;

	array = ft_strsplit(line, ';');
	if (ft_strequ(array[0], "OBJECT_SPHERE"))
		error = parse_sphere_array(array, m);
	else if (ft_strequ(array[0], "OBJECT_PLANE"))
		error = parse_plane_array(array, m);
	else if (ft_strequ(array[0], "OBJECT_DISK"))
		error = parse_disk_array(array, m);
	else if (ft_strequ(array[0], "OBJECT_CYLINDER"))
		error = parse_cylinder_array(array, m);
	else if (ft_strequ(array[0], "OBJECT_CONE"))
		error = parse_cone_array(array, m);
	else
		error = 1;
	ft_char_array_del(array);
	return (error);
}

static int		parse_line(char *line, t_master *m)
{
	if (!line || line[0] == '\0' || line[0] == '#')
		return (0);
	if (BEGINS_WITH(line, "CAMERA"))
	{
		if (parse_camera_line(line, m))
			return (ft_puterror(ERROR_LINE, line, 1));
	}
	else if (BEGINS_WITH(line, "LIGHT"))
	{
		if (parse_light_line(line, m))
			return (ft_puterror(ERROR_LINE, line, 1));
	}
	else if (BEGINS_WITH(line, "OBJECT"))
	{
		if (parse_obj_line(line, m))
			return (ft_puterror(ERROR_LINE, line, 1));
	}
	else
		return (ft_puterror(ERROR_LINE, line, 1));
	return (0);
}

int				parse_file(char *filename, t_master *m)
{
	int			fd;
	char		*line;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (ft_puterror(ERROR_OPEN_FILE, filename, 1));
	line = 0;
	get_next_line(fd, &line);
	while (line)
	{
		if (parse_line(line, m))
		{
			ft_strdel(&line);
			close(fd);
			return (1);
		}
		del_and_gnl(fd, &line);
	}
	if (close(fd) < 0)
		return (ft_puterror(ERROR_CLOSE_FILE, filename, 1));
	return (0);
}
