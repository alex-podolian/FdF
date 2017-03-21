/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:05:36 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/21 15:38:36 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_clean_mem(t_list **list, t_map **m)
{
	t_list	*next;

	while (*list)
	{
		next = (*list)->next;
		ft_memdel(&(*list)->content);
		ft_memdel((void **)list);
		*list = next;
	}
	if (m && *m)
	{
		ft_memdel((void **)&(*m)->vector);
		ft_memdel((void **)m);
	}
	return (0);
}

static t_vector	*ft_init_vector(int x, int y, char *str)
{
	t_vector	*v;

	if (!(v = ft_memalloc(sizeof(t_vector))))
		return (0);
	v->x = (double)x;
	v->y = (double)y;
	v->z = (double)ft_atoi(str);
	v->color = 0xFFFFFF;
	return (v);
}

static int		ft_fill_map(t_map **m, t_list *list)
{
	t_list	*lst;
	int		x;
	int		y;
	char	**split;

	lst = list;
	y = -1;
	while (++y < (*m)->height)
	{
		x = -1;
		if (!(split = ft_strsplit(lst->content, ' ')))
			return (ft_clean_mem(&list, m));
		while (++x < (*m)->width)
			(*m)->vector[y * (*m)->width + x] = ft_init_vector(x, y, split[x]);
		ft_split_del(&split);
		lst = lst->next;
	}
	ft_depth(*m);
	ft_colors(*m);
	ft_clean_mem(&list, 0);
	return (1);
}

static int		ft_get_line(int fd, t_list **list)
{
	t_list	*tmp;
	int		ret;
	char	*line;
	int		count;

	count = -1;
	while ((ret = get_next_line(fd, &line)))
	{
		if (count == -1)
			count = ft_word_count(line, ' ');
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		if (!tmp)
			return (ft_clean_mem(list, 0));
		ft_lstadd(list, tmp);
		if (count != ft_word_count(line, ' '))
			return (ft_clean_mem(list, 0));
		ft_strdel(&line);
	}
	if (count == -1 || ret == -1)
		return (ft_clean_mem(list, 0));
	ft_lstrev(list);
	return (1);
}

int				ft_validate_map(int fd, t_map **m)
{
	t_list	*list;

	list = 0;
	if (!(ft_get_line(fd, &list)))
		return (0);
	if (!(*m = ft_memalloc(sizeof(t_map))))
		return (ft_clean_mem(&list, m));
	(*m)->width = ft_word_count(list->content, ' ');
	(*m)->height = ft_lstcount(list);
	(*m)->min_depth = 0;
	(*m)->max_depth = 0;
	(*m)->vector = ft_memalloc(sizeof(t_vector *) * (*m)->width * (*m)->height);
	if (!(*m)->vector)
	{
		ft_memdel((void **)&(*m));
		return (ft_clean_mem(&list, m));
	}
	return (ft_fill_map(m, list));
}
