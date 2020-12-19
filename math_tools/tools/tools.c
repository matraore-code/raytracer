/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 05:27:31 by matraore          #+#    #+#             */
/*   Updated: 2020/12/12 00:07:53 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include <limits.h>
#include <string.h>

void		tools_memory_init(void)
{
	g_global_memory = 0;
}

void		*tools_malloc(int alloc)
{
	void	*ptr;

	ptr = malloc(alloc);
	if (ptr == NULL)
		return (NULL);
	g_global_memory += alloc;
	return (ptr);
}

void		tools_free(void **ptr, int alloc)
{
	free(*ptr);
	*ptr = NULL;
	g_global_memory -= alloc;
}

void		tools_memory_check_at_end_of_app(void)
{
	if (g_global_memory != 0)
		printf("Ce programme a une fuite de memoire.");
}

int			equal(double n1, double n2)
{
	if (fabs(n1 - n2) < EPSILON)
		return (1);
	else
		return (0);
}
