/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depth_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:06:09 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/20 20:41:35 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	ft_point(double val, double min, double max)
{
	if (val == min)
		return (0.0);
	if (val == max)
		return (1.0);
	return ((val - min) / (max - min));
}

static int		ft_rgb(int c_1, int c_2, double p)
{
	if (c_1 == c_2)
		return (c_1);
	return ((int)((double)c_1 + (c_2 - c_1) * p));
}

static int		ft_get_color(int c_1, int c_2, double p)
{
	int		r;
	int		g;
	int		b;

	if (c_1 == c_2)
		return (c_1);
	r = ft_rgb((c_1 >> 16) & 0xFF, (c_2 >> 16) & 0xFF, p);
	g = ft_rgb((c_1 >> 8) & 0xFF, (c_2 >> 8) & 0xFF, p);
	b = ft_rgb(c_1 & 0xFF, c_2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}

void			ft_colors(t_map *m)
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
			curr->color = ft_get_color(0xFF0000, 0xFFFFFF, ft_ilerp(curr->z,
				m->min_depth, m->max_depth));
		}
	}
}

void			ft_depth(t_map *m)
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
