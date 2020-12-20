
#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <mach/thread_act.h>

# define ERROR_USAGE			"usage: RTv1 input_file"
# define ERROR_MEMORY			"Out of memory"
# define ERROR_OPEN_FILE		"Cannot open file"
# define ERROR_CLOSE_FILE		"Cannot close file"
# define ERROR_LINE				"Invalid line"
# define ERROR_NO_LIGHT			"No light in this scene"
# define ERROR_NO_OBJECT		"No object in this scene"
# define ERROR_COLOR			"Invalid color"
# define ERROR_NUM_TERMS		"Invalid number of terms"

# define WIN_WIDTH				400
# define WIN_HEIGHT				300
# define WIN_NAME				"RTv1"
# define THREAD_COUNT			4

# define SWAP(a, b, T)			{T temp = a; a = b; b = temp;}
# define DEG_TO_RAD(a)			((a) * M_PI / 180.0)
# define MAX(a, b)				((a) > (b) ? (a) : (b))
# define MIN(a, b)				((a) < (b) ? (a) : (b))
# define SQ(a)					((a) * (a))
# define CLAMP(d, d_min, d_max)	(d = MIN(MAX(d_min, d), d_max))
# define BEGINS_WITH(s, t)		ft_strnequ(s, t, ft_strlen(t))
# define IN_RANGE(d, d_min, d_max)	(d_min <= d && d <= d_max)

# define BG_COLOR				0x0099ff
# define SHADOW_BIAS			0.001
# define TINY_VALUE				1e-8

# define DEF_FOV_H				60.0
# define DEF_FOV_V				60.0
# define FOV_INC				5.0
# define FOV_MIN				0.0
# define FOV_MAX				180.0

# define CAM_ROT_INC			5.0
# define CAM_POS_INC			1.0

# define LIGHT_INTENSITY_INC	0.02
# define LIGHT_POS_INC			0.2
# define LIGHT_ROT_INC			5.0

# define K_DIFFUSE_INC			0.02
# define K_SPECULAR_INC			0.02
# define PHONG_N_INC			0.5
# define PHONG_N_MIN			0.0
# define PHONG_N_MAX			20.0

# define OBJ_POS_INC			0.2
# define OBJ_ROT_INC			5.0

# define TYPE_V3				typedef double t_vect3 TYPE_V3_2
# define TYPE_V3_2				__attribute__((vector_size(3 * sizeof(double))))

TYPE_V3;

typedef struct		s_matrix
{
	t_vect3			r0;
	t_vect3			r1;
	t_vect3			r2;
}					t_matrix;

typedef struct		s_quadratic
{
	double			a;
	double			b;
	double			c;
	double			x0;
	double			x1;
}					t_quadratic;

typedef struct		s_camera
{
	double			fov_h;
	double			fov_v;

	t_vect3			pos;

	double			rot_x;
	double			rot_y;
	double			rot_z;
	t_matrix		rot_matrix;
}					t_camera;

enum				e_light_type
{
	DISTANT_LIGHT,
	POINT_LIGHT
};

/*
** Point Light:			pos
** Distant Light:		dir
*/
typedef struct		s_light
{
	char				*name;
	enum e_light_type	type;
	int					on_state;
	double				intensity;
	t_vect3				color;

	t_vect3				pos;
	t_vect3				dir;
	t_vect3				dir_0;

	double				rot_x;
	double				rot_y;
	double				rot_z;
	t_matrix			rot_matrix;
}					t_light;

enum				e_obj_type
{
	SPHERE_OBJ,
	PLANE_OBJ,
	DISK_OBJ,
	CYLINDER_OBJ,
	CONE_OBJ,
};

/*
** Sphere:			center, radius
** Plane:			center, normal
** Disk:			center, normal, radius
** Cylinder:		center, dir, radius
** Cone:			center, dir, half_angle
*/
typedef struct		s_obj
{
	char			*name;
	enum e_obj_type	type;
	int				(*intersect)();
	t_vect3			color;
	double			k_diffuse;
	double			k_specular;
	double			phong_n;

	t_vect3			center;
	t_vect3			normal;
	t_vect3			normal_0;
	double			radius;
	t_vect3			dir;
	t_vect3			dir_0;
	double			half_angle;

	double			rot_x;
	double			rot_y;
	double			rot_z;
	t_matrix		rot_matrix;
}					t_obj;

typedef struct		s_ray
{
	t_vect3			orig;
	t_vect3			dir;
	double			t;
	t_vect3			color;
	t_vect3			final_color;
	t_obj			*hit_obj;
}					t_ray;

typedef struct		s_mlx
{
	void			*appid;
	void			*win_list;
	void			*img_list;
	void			(*loop_hook)(void *);
	void			*loop_hook_data;
	void			*loop_timer;
	void			**font;
	int				main_loop_active;
}					t_mlx;

typedef struct		s_master
{
	t_mlx			*mlx;
	void			*win;
	void			*img;
	int				*frame;
	int				bpp;
	int				size_line;
	int				endian;

	int				shift_down;

	t_camera		cam;

	t_list			*light_list;
	t_light			*light;
	int				light_index;

	t_list			*obj_list;
	t_obj			*obj;

	int				files_saved;
}					t_master;

enum				e_key
{
	ESC = 53,
	TILDE = 50,
	LEFT_SHIFT = 257,

	NUMPAD_MINUS = 78,
	NUMPAD_PLUS = 69,
	NUMPAD_7 = 89,
	NUMPAD_8 = 91,
	NUMPAD_4 = 86,
	NUMPAD_5 = 87,
	NUMPAD_1 = 83,
	NUMPAD_2 = 84,

	TAB = 48,
	O_KEY = 31,
	ALPHA_MINUS = 27,
	ALPHA_PLUS = 24,
	Q_KEY = 12,
	W_KEY = 13,
	A_KEY = 0,
	S_KEY = 1,
	Z_KEY = 6,
	X_KEY = 7,

	LMB = 1,
	DOWN_ARROW = 125,
	UP_ARROW = 126,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124,
	T_KEY = 17,
	Y_KEY = 16,
	G_KEY = 5,
	H_KEY = 4,
	B_KEY = 11,
	N_KEY = 45
};

typedef struct		s_key_func
{
	int				key;
	void			(*func)(t_master *);
}					t_key_func;

/*
** matrix.c
*/
void				init_rot_matrix(t_matrix *m, double rot_x, double rot_y,
	double rot_z);

/*
** vect3.c
*/
void				v_init(t_vect3 *v, double x, double y, double z);
void				v_normalize(t_vect3 *v);
double				v_dist(t_vect3 *src, t_vect3 *dst);
void				v_dir(t_vect3 *src, t_vect3 *dst, t_vect3 *dir);
int					v_is_zero(t_vect3 *v);

/*
** vect3_2.c
*/
double				v_dot(t_vect3 *v1, t_vect3 *v2);
void				v_cross(t_vect3 *v1, t_vect3 *v2, t_vect3 *result);
void				v_mult(double scalar, t_vect3 *v, t_vect3 *result);
void				mult_matrix_vector(t_matrix *m, t_vect3 *v, t_vect3 *r);

/*
** vect3_3.c
*/
void				v_add(t_vect3 *v1, t_vect3 *v2, t_vect3 *result);
void				v_subtract(t_vect3 *v1, t_vect3 *v2, t_vect3 *result);

/*
** keys.c
*/
int					key_release_hook(int keycode, t_master *m);
int					key_press_hook(int keycode, t_master *m);

/*
** keys_2.c
*/
void				terminate(t_master *m);
void				dec_fov(t_master *m);
void				inc_fov(t_master *m);
void				dec_cam_x(t_master *m);
void				inc_cam_x(t_master *m);

/*
** keys_3.c
*/
void				dec_cam_y(t_master *m);
void				inc_cam_y(t_master *m);
void				dec_cam_z(t_master *m);
void				inc_cam_z(t_master *m);

/*
** keys_4.c
*/
void				select_next_light(t_master *m);
void				toggle_light(t_master *m);
void				dec_light_intensity(t_master *m);
void				inc_light_intensity(t_master *m);
void				dec_light_x(t_master *m);

/*
** keys_5.c
*/
void				inc_light_x(t_master *m);
void				dec_light_y(t_master *m);
void				inc_light_y(t_master *m);
void				dec_light_z(t_master *m);
void				inc_light_z(t_master *m);

/*
** keys_6.c
*/
void				dec_obj_phong_n(t_master *m);
void				inc_obj_phong_n(t_master *m);
void				dec_obj_k(t_master *m);
void				inc_obj_k(t_master *m);
void				dec_obj_x(t_master *m);

/*
** keys_7.c
*/
void				inc_obj_x(t_master *m);
void				dec_obj_y(t_master *m);
void				inc_obj_y(t_master *m);
void				dec_obj_z(t_master *m);
void				inc_obj_z(t_master *m);

/*
** mouse.c
*/
int					mouse_button_down(int button, int x, int y, t_master *m);

/*
** ppm.c
*/
int					save_ppm(t_master *m);

/*
** quadratic.c
*/
int					solve_quadratic(t_quadratic *q, double *t);
int					check_quadratic_results(t_quadratic *q, double *t);

/*
** intersect.c
*/
int					sphere_intersect(t_obj *obj, t_ray *ray, double *t);
int					plane_intersect(t_obj *obj, t_ray *ray, double *t);
int					disk_intersect(t_obj *obj, t_ray *ray, double *t);
int					cylinder_intersect(t_obj *obj, t_ray *ray, double *t);
int					cone_intersect(t_obj *obj, t_ray *ray, double *t);

/*
** surface.c
*/
void				get_surface(t_ray *ray, t_vect3 *hit_point,
	t_vect3 *hit_normal);

/*
** color.c
*/
void				draw_dot(int x, int y, t_vect3 *color, t_master *m);
void				set_color(t_vect3 *color, int color_num);
void				clamp_color(t_vect3 *color);

/*
** light.c
*/
int					add_light(t_list **light_list, char *name,
	enum e_light_type type, t_vect3 *v);
int					light_count(t_list *light_list);
void				print_all_lights(t_list *lights, t_light *selected);

/*
** object.c
*/
void				print_all_objects(t_list *object_list, t_obj *selected);

/*
** object_2.c
*/
void				print_sphere_obj(t_obj *obj);
void				print_plane_obj(t_obj *obj);
void				print_disk_obj(t_obj *obj);
void				print_cylinder_obj(t_obj *obj);
void				print_cone_obj(t_obj *obj);

/*
** parse_camera.c
*/
int					parse_camera_line(char *line, t_master *m);

/*
** parse_light.c
*/
int					parse_light_line(char *line, t_master *m);

/*
** parse_object.c
*/
int					parse_sphere_array(char **array, t_master *m);
int					parse_plane_array(char **array, t_master *m);
int					parse_disk_array(char **array, t_master *m);
int					parse_cylinder_array(char **array, t_master *m);
int					parse_cone_array(char **array, t_master *m);

/*
** parser.c
*/
int					parse_vector(char *str, t_vect3 *v);
int					parse_any_obj_array(char **array, t_obj *obj);
int					parse_file(char *filename, t_master *m);

/*
** render.c
*/
void				render(t_master *m);
void				print_info(t_master *m);

/*
** render_2.c
*/
int					trace(t_ray *ray, t_list *obj_list);
void				raycast(t_ray *ray, t_list *obj_list, t_list *light_list);
void				init_ray(t_ray *ray, double x, double y, t_camera *cam);

/*
** render_3.c
*/
int					shadow_cast(t_vect3 *hit_point, t_light *light,
	t_list *obj_list);
void				add_color_from_light(t_ray *ray, t_light *light,
	t_vect3 *hit_point, t_vect3 *hit_normal);

/*
** render_th.c
*/
void				render_th_master(t_master *m);

/*
** main.c
*/
int					main(int argc, char **argv);

/*
** freedom.c
*/
int					free_all(t_master *m, char *message);

#endif
