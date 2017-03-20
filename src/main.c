/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:56:17 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/20 20:24:54 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_error(char *str)
{
	ft_putstr(str);
	return (1);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc != 2)
		return (ft_error("usage: ./fdf source_file\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || !ft_validate_map(fd, &map))
		return (ft_error("error: invalid file\n"));
	return (0);
}
