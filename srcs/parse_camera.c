

#include "rtv1.h"

static int	parse_triple(char *str, double *x, double *y, double *z)
{
	char	**array;
	int		error;

	error = 0;
	array = ft_strsplit(str, ',');
	if (ft_char_array_length(array) != 3)
		error = 1;
	else
	{
		*x = ft_atodbl(array[0]);
		*y = ft_atodbl(array[1]);
		*z = ft_atodbl(array[2]);
	}
	ft_char_array_del(array);
	return (error);
}

/*
** array[0] = CAMERA
** array[1] = fov in [0.0, 180.0]
** array[2] = position (vector)
** array[3] = rot_angles (x,y,z)
*/

int			parse_camera_line(char *line, t_master *m)
{
	char	**array;
	int		error;

	error = 0;
	array = ft_strsplit(line, ';');
	if (ft_char_array_length(array) == 4)
	{
		m->cam.fov_h = ft_atodbl(array[1]);
		m->cam.fov_v = m->cam.fov_h;
		if (!IN_RANGE(m->cam.fov_h, FOV_MIN, FOV_MAX))
			error = ft_puterror("Invalid fov", array[1], 1);
		if (parse_vector(array[2], &m->cam.pos))
			error = ft_puterror("Invalid position", array[2], 1);
		if (parse_triple(array[3], &m->cam.rot_x, &m->cam.rot_y, &m->cam.rot_z))
			error = ft_puterror("Invalid rotation angles", array[3], 1);
	}
	else
		error = ft_puterror(ERROR_NUM_TERMS, 0, 1);
	ft_char_array_del(array);
	return (error);
}
