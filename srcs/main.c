

#include "rtv1.h"

static int		init_mlx_stuff(t_master *m)
{
	if (!(m->mlx = mlx_init()) ||
		!(m->win = mlx_new_window(m->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME)) ||
		!(m->img = mlx_new_image(m->mlx, WIN_WIDTH, WIN_HEIGHT)) ||
		!(m->frame = (int *)mlx_get_data_addr(m->img, &(m->bpp),
			&(m->size_line), &(m->endian))))
		return (ft_puterror(ERROR_MEMORY, 0, 1));
	render(m);
	mlx_hook(m->win, 2, 0, key_press_hook, m);
	mlx_hook(m->win, 3, 0, key_release_hook, m);
	mlx_hook(m->win, 4, 0, mouse_button_down, m);
	mlx_hook(m->win, 17, 0, (int (*)())terminate, m);
	return (0);
}

int				main(int argc, char **argv)
{
	t_master	m;

	if (argc != 2)
		return (ft_puterror(ERROR_USAGE, 0, 0));
	ft_bzero(&m, sizeof(t_master));
	m.cam.fov_h = DEF_FOV_H;
	m.cam.fov_v = DEF_FOV_V;
	if (parse_file(argv[1], &m))
		return (free_all(&m, 0));
	if (ft_lst_size(m.light_list) == 0)
		return (free_all(&m, ERROR_NO_LIGHT));
	m.light = m.light_list->content;
	if (ft_lst_size(m.obj_list) == 0)
		return (free_all(&m, ERROR_NO_OBJECT));
	m.obj = m.obj_list->content;
	if (init_mlx_stuff(&m))
		return (free_all(&m, 0));
	mlx_loop(m.mlx);
	return (0);
}
