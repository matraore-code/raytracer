/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 05:38:53 by matraore          #+#    #+#             */
/*   Updated: 2020/12/11 04:52:26 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# define TRUE 1
# define FALSE 0
# define EPSILON 0.00001

int			g_global_memory;
double		square(double x);
double		degre_to_radian(double angle);
void		tools_memory_init (void);
void		*tools_malloc(int alloc);
void		tools_free(void **ptr, int alloc);
void		tools_memory_check_at_end_of_app(void);
int			equal(double n1, double n2);

#endif
