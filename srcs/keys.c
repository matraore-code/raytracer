/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 09:59:23 by ashih             #+#    #+#             */
/*   Updated: 2018/04/10 04:44:35 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** Key						Function
**
** ESC						Terminate program
** TILDE (~)				Save image to PPM file
** LEFT_SHIFT				Toggle SHIFT state on/off
**
** -----------------------------------------------------------------------------
** CAMERA CONTROLS
** -----------------------------------------------------------------------------
** NUMPAD +					Inc FOV (Zoom out)
** NUMPAD -					Dec FOV (Zoom in)
**
** NUMPAD 7					Move cam position toward -x
** NUMPAD 8					Move cam position toward +x
** NUMPAD 4					Move cam position toward -y
** NUMPAD 5					Move cam position toward +y
** NUMPAD 1					Move cam position toward -z
** NUMPAD 2					Move cam position toward +z
**
** SHIFT + NUMPAD 7			Dec cam rotation around x-axis
** SHIFT + NUMPAD 8			Inc cam rotation around x-axis
** SHIFT + NUMPAD 4			Dec cam rotation around y-axis
** SHIFT + NUMPAD 5			Inc cam rotation around y-axis
** SHIFT + NUMPAD 1			Dec cam rotation around z-axis
** SHIFT + NUMPAD 2			Inc cam rotation around z-axis
**
** -----------------------------------------------------------------------------
** LIGHT CONTROLS
** -----------------------------------------------------------------------------
** TAB						Select next light
** O						Turn selected light on/off
**
** ALPHA +					Inc selected light's intensity
** ALPHA -					Inc selected light's intensity
**
** Q						Dec selected light's pos.x or dir.x
** W						Inc selected light's pos.x or dir.x
** A						Dec selected light's pos.y or dir.y
** S						Inc selected light's pos.y or dir.y
** Z						Dec selected light's pos.z or dir.z
** X						Inc selected light's pos.z or dir.z
**
** -----------------------------------------------------------------------------
** OBJECT CONTROLS
** -----------------------------------------------------------------------------
** Mouse LMB				Select object
**
** DOWN ARROW				Dec selected obj's phong_n
** UP ARROW					Inc selected obj's phong_n
**
** LEFT ARROW				Dec selected obj's k_diffuse
** RIGHT ARROW				Inc selected obj's k_diffuse
**
** SHIFT + LEFT ARROW		Dec selected obj's k_specular
** SHIFT + RIGHT ARROW		Inc selected obj's k_specular
**
** T						Move selected obj toward -x
** Y						Move selected obj toward +x
** G						Move selected obj toward -y
** H						Move selected obj toward +y
** B						Move selected obj toward -z
** N						Move selected obj toward +z
**
** SHIFT + T				Dec selected obj rotation around x-axis
** SHIFT + Y				Inc selected obj rotation around x-axis
** SHIFT + G				Dec selected obj rotation around y-axis
** SHIFT + H				Inc selected obj rotation around y-axis
** SHIFT + B				Dec selected obj rotation around z-axis
** SHIFT + N				Inc selected obj rotation around z-axis
*/

t_key_func g_table[] =
{
	{ESC, terminate},
	{TILDE, (void (*)(t_master *))save_ppm},

	{NUMPAD_MINUS, dec_fov},
	{NUMPAD_PLUS, inc_fov},
	{NUMPAD_7, dec_cam_x},
	{NUMPAD_8, inc_cam_x},
	{NUMPAD_4, dec_cam_y},
	{NUMPAD_5, inc_cam_y},
	{NUMPAD_1, dec_cam_z},
	{NUMPAD_2, inc_cam_z},

	{TAB, select_next_light},
	{O_KEY, toggle_light},
	{ALPHA_MINUS, dec_light_intensity},
	{ALPHA_PLUS, inc_light_intensity},
	{Q_KEY, dec_light_x},
	{W_KEY, inc_light_x},
	{A_KEY, dec_light_y},
	{S_KEY, inc_light_y},
	{Z_KEY, dec_light_z},
	{X_KEY, inc_light_z},

	{DOWN_ARROW, dec_obj_phong_n},
	{UP_ARROW, inc_obj_phong_n},
	{LEFT_ARROW, dec_obj_k},
	{RIGHT_ARROW, inc_obj_k},
	{T_KEY, dec_obj_x},
	{Y_KEY, inc_obj_x},
	{G_KEY, dec_obj_y},
	{H_KEY, inc_obj_y},
	{B_KEY, dec_obj_z},
	{N_KEY, inc_obj_z},

	{-1, 0}
};

int				key_release_hook(int keycode, t_master *m)
{
	if (keycode == LEFT_SHIFT)
		m->shift_down = 0;
	return (0);
}

int				key_press_hook(int keycode, t_master *m)
{
	int			i;

	if (keycode == LEFT_SHIFT)
		m->shift_down = 1;
	i = 0;
	while (g_table[i].key != -1)
	{
		if (g_table[i].key == keycode)
		{
			g_table[i].func(m);
			render(m);
			return (0);
		}
		i++;
	}
	return (0);
}

/*
**int				key_press_hook(int keycode, t_master *m)
**{
**	if (keycode == LEFT_SHIFT)
**		m->shift_down = 1;
**
**	if (keycode == ESC)
**		terminate(m);
**	else if (keycode == TILDE)
**		save_ppm(m);
**
**	// -----------------------------------------------------------------------
**	// CAMERA CONTROLS
**	// -----------------------------------------------------------------------
**	else if (keycode == NUMPAD_PLUS)
**	{
**		m->cam.fov_h -= FOV_INC;
**		m->cam.fov_v -= FOV_INC;
**		CLAMP(m->cam.fov_h, FOV_MIN, FOV_MAX);
**		CLAMP(m->cam.fov_v, FOV_MIN, FOV_MAX);
**	}
**	else if (keycode == NUMPAD_MINUS)
**	{
**		m->cam.fov_h += FOV_INC;
**		m->cam.fov_v += FOV_INC;
**		CLAMP(m->cam.fov_h, FOV_MIN, FOV_MAX);
**		CLAMP(m->cam.fov_v, FOV_MIN, FOV_MAX);
**	}
**	else if (keycode == NUMPAD_7)
**	{
**		if (m->shift_down)
**			m->cam.rot_x -= CAM_ROT_INC;
**		else
**			m->cam.pos.x -= CAM_POS_INC;
**	}
**	else if (keycode == NUMPAD_8)
**	{
**		if (m->shift_down)
**			m->cam.rot_x += CAM_ROT_INC;
**		else
**			m->cam.pos.x += CAM_POS_INC;
**	}
**	else if (keycode == NUMPAD_4)
**	{
**		if (m->shift_down)
**			m->cam.rot_y -= CAM_ROT_INC;
**		else
**			m->cam.pos.y -= CAM_POS_INC;
**	}
**	else if (keycode == NUMPAD_5)
**	{
**		if (m->shift_down)
**			m->cam.rot_y += CAM_ROT_INC;
**		else
**			m->cam.pos.y += CAM_POS_INC;
**	}
**	else if (keycode == NUMPAD_1)
**	{
**		if (m->shift_down)
**			m->cam.rot_z -= CAM_ROT_INC;
**		else
**			m->cam.pos.z -= CAM_POS_INC;
**	}
**	else if (keycode == NUMPAD_2)
**	{
**		if (m->shift_down)
**			m->cam.rot_z += CAM_ROT_INC;
**		else
**			m->cam.pos.z += CAM_POS_INC;
**	}
**
**	// -----------------------------------------------------------------------
**	// LIGHT CONTROLS
**	// -----------------------------------------------------------------------
**	else if (keycode == TAB)
**		select_next_light(m);
**	else if (keycode == O_KEY)
**		m->light->on_state = !m->light->on_state;
**	else if (keycode == ALPHA_PLUS)
**	{
**		m->light->intensity += LIGHT_INTENSITY_INC;
**		CLAMP(m->light->intensity, 0.0, 1.0);
**	}
**	else if (keycode == ALPHA_MINUS)
**	{
**		m->light->intensity -= LIGHT_INTENSITY_INC;
**		CLAMP(m->light->intensity, 0.0, 1.0);
**	}
**	else if (keycode == Q_KEY)
**	{
**		if (m->light->type == POINT_LIGHT)
**			m->light->pos.x -= LIGHT_POS_INC;
**		else
**			m->light->rot_x -= LIGHT_ROT_INC;
**	}
**	else if (keycode == W_KEY)
**	{
**		if (m->light->type == POINT_LIGHT)
**			m->light->pos.x += LIGHT_POS_INC;
**		else
**			m->light->rot_x += LIGHT_ROT_INC;
**	}
**	else if (keycode == A_KEY)
**	{
**		if (m->light->type == POINT_LIGHT)
**			m->light->pos.y -= LIGHT_POS_INC;
**		else
**			m->light->rot_y -= LIGHT_ROT_INC;
**	}
**	else if (keycode == S_KEY)
**	{
**		if (m->light->type == POINT_LIGHT)
**			m->light->pos.y += LIGHT_POS_INC;
**		else
**			m->light->rot_y += LIGHT_ROT_INC;
**	}
**	else if (keycode == Z_KEY)
**	{
**		if (m->light->type == POINT_LIGHT)
**			m->light->pos.z -= LIGHT_POS_INC;
**		else
**			m->light->rot_z -= LIGHT_ROT_INC;
**	}
**	else if (keycode == X_KEY)
**	{
**		if (m->light->type == POINT_LIGHT)
**			m->light->pos.z += LIGHT_POS_INC;
**		else
**			m->light->rot_z += LIGHT_ROT_INC;
**	}
**
**	// -----------------------------------------------------------------------
**	// OBJECT CONTROLS
**	// -----------------------------------------------------------------------
**	else if (keycode == DOWN_ARROW)
**	{
**		m->obj->phong_n -= PHONG_N_INC;
**		CLAMP(m->obj->phong_n, PHONG_N_MIN, PHONG_N_MAX);
**	}
**	else if (keycode == UP_ARROW)
**	{
**		m->obj->phong_n += PHONG_N_INC;
**		CLAMP(m->obj->phong_n, PHONG_N_MIN, PHONG_N_MAX);
**	}
**	else if (keycode == LEFT_ARROW)
**	{
**		if (m->shift_down)
**		{
**			m->obj->k_specular -= K_SPECULAR_INC;
**			CLAMP(m->obj->k_specular, 0.0, 1.0);
**		}
**		else
**		{
**			m->obj->k_diffuse -= K_DIFFUSE_INC;
**			CLAMP(m->obj->k_diffuse, 0.0, 1.0);
**		}
**	}
**	else if (keycode == RIGHT_ARROW)
**	{
**		if (m->shift_down)
**		{
**			m->obj->k_specular += K_SPECULAR_INC;
**			CLAMP(m->obj->k_specular, 0.0, 1.0);
**		}
**		else
**		{
**			m->obj->k_diffuse += K_DIFFUSE_INC;
**			CLAMP(m->obj->k_diffuse, 0.0, 1.0);
**		}
**	}
**	else if (keycode == T_KEY)
**	{
**		if (m->shift_down)
**			m->obj->rot_x -= OBJ_ROT_INC;
**		else
**			m->obj->center.x -= OBJ_POS_INC;
**	}
**	else if (keycode == Y_KEY)
**	{
**		if (m->shift_down)
**			m->obj->rot_x += OBJ_ROT_INC;
**		else
**			m->obj->center.x += OBJ_POS_INC;
**	}
**	else if (keycode == G_KEY)
**	{
**		if (m->shift_down)
**			m->obj->rot_y -= OBJ_ROT_INC;
**		else
**			m->obj->center.y -= OBJ_POS_INC;
**	}
**	else if (keycode == H_KEY)
**	{
**		if (m->shift_down)
**			m->obj->rot_y += OBJ_ROT_INC;
**		else
**			m->obj->center.y += OBJ_POS_INC;
**	}
**	else if (keycode == B_KEY)
**	{
**		if (m->shift_down)
**			m->obj->rot_z -= OBJ_ROT_INC;
**		else
**			m->obj->center.z -= OBJ_POS_INC;
**	}
**	else if (keycode == N_KEY)
**	{
**		if (m->shift_down)
**			m->obj->rot_z += OBJ_ROT_INC;
**		else
**			m->obj->center.z += OBJ_POS_INC;
**	}
**
**	render(m);
**	return (0);
**}
*/
