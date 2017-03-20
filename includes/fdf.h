/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:24:21 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/20 20:35:31 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft_printf/includes/ft_printf.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <stdio.h>

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_vector;

typedef struct	s_map
{
	int			height;
	int			width;
	int			min_depth;
	int			max_depth;
	t_vector	**vector;
}				t_map;

int				ft_validate_map(int fd, t_map **m);
t_vector		*ft_vector(int x, int y, char *str);
void			ft_depth(t_map *m);
void			ft_colors(t_map *m);

#endif
