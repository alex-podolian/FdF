/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:06:09 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/20 20:41:35 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_colors(t_map *m)
{
	t_vector	v;
	t_vector	*curr;

	v.y = -1;
	while (++v.y < m->height)
	{
		v.x = -1;
		while (++v.x < m->width)
		{
			curr = m->vector[(int)v.y * m->width + (int)v.x];
			curr->color = clerp(0xFF0000, 0xFFFFFF, ft_ilerp(curr->z,
				m->min_depth, m->max_depth));
		}
	}
}

void		ft_depth(t_map *m)
{
	int			min;
	int			max;
	t_vector	v;
	t_vector	curr;

	min = INT_MAX;
	max = INT_MIN;
	v.y = -1;
	while (++v.y < m->height)
	{
		v.x = -1;
		while (++v.x < m->width)
		{
			curr = *m->vector[(int)v.y * m->width + (int)v.x];
			if (curr.z < min)
				min = curr.z;
			if (curr.z > max)
				max = curr.z;
		}
	}
	m->min_depth = min;
	m->max_depth = max;
}

t_vector	*ft_vector(int x, int y, char *str)
{
	t_vector	*v;

	if (!(v = ft_memalloc(sizeof(t_vector))))
		return (0);
	v->x = (double)x;
	v->y = (double)y;
	v->z = (double)ft_atoi(str);
	printf("str = %s\n", str);
	printf("v->z = %f\n", v->z);
	v->color = 0xFFFFFF;
	return (v);
}
