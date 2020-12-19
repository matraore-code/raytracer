/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 00:03:17 by matraore          #+#    #+#             */
/*   Updated: 2020/12/19 02:44:47 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void		init_window()
{
	g_window.mlx_ptr = mlx_init();
	//g_window.win_ptr = NULL;
	g_window.win_title = "MiniRT";
}

void		open_window()
{
	g_window.win_ptr = mlx_new_window(g_window.mlx_ptr, g_window.res.width,
			g_window.res.height, g_window.win_title);
}

int			run_win()
{
	mlx_loop(g_window.mlx_ptr);
	return (1);
}


