/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 00:00:20 by matraore          #+#    #+#             */
/*   Updated: 2020/12/19 02:59:54 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_mangement/display.h"
#include "math_tools/math.h"
#include <stdio.h>

int main ()
{
	int x = 0;
	int y;

	t_canvas canvas = create_canvas(600, 1000);
	t_canvas canvas1 = create_canvas(200, 200);
	canvas1.color = 16777215;
	g_window.res.width = 600;
	g_window.res.height = 1000;
	printf("%d", canvas1.color);
	init_window();
	open_window();
	//while (x < 600)
//	{
	//	y = 0;
	//	while (y < 1000)
	//	{
	//		img_to_window(x, y, canvas);
	//		y++;
	//	}
	//	x++;
//	}

	x= 0;
	while (x < 200)
	{
		y = 0;
		while (y < 200)
		{
			img_to_window(x, y, canvas1);
			y++;
		}
		x++;
	}
	run_win();
//	return (0);
}
