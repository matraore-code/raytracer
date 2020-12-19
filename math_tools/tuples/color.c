/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 02:59:53 by matraore          #+#    #+#             */
/*   Updated: 2020/12/19 00:29:06 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_color			color(float red, float green, float blue)
{
	t_color		c;

	c.red = red;
	c.green = green;
	c.blue = blue;
	return (c);
}

t_color			adding_color(t_color c, t_color d)
{
	return (color(c.red + d.red, c.green + d.green, c.blue + d.blue));
}

t_color			sub_color(t_color c, t_color d)
{
	return (color(c.red - d.red, c.green - d.green, c.blue - d.blue));
}

t_color			multip_color(t_color c, t_color d)
{
	return (color(c.red * d.red, c.green * d.green, c.blue * d.blue));
}

t_color			scalar_color(float c, t_color d)
{
	return (color(c * d.red, c * d.green, c * d.blue));
}
