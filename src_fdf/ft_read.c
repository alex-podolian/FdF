/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:20:08 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/17 19:45:57 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
static int	ft_mem_clean(t_list **list, t_map **map)
{
	t_list	*next;

	while (*list)
	{
		next = *list->next;
		ft_memdel(&(*lst)->content);
		ft_memdel((void **)list);
		*list = next;
	}
	if (map && *map)
	{
		ft_memdel((void **)&(*map)->vector);
		ft_memdel((void **)map);
	}
	return (0);
}

static int	ft_get_line(int fd, t_list **list)
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
		if (tmp == NULL)
			return (ft_mem_clean(list, NULL));
		ft_lstadd(list, tmp);
		if (count != ft_word_count(line, ' '))
			return (ft_mem_clean(list, NULL));
		ft_strdel(&line);
	}
	if (count == -1 || ret == -1)
		return (ft_mem_clean(list, NULL));
	ft_lstrev(lst);
	return (1);
}

int		ft_read(int fd, t_map **map)
{
	t_list	*list;

	list = NULL;
	if (!(ft_get_line(fd, &list)))
		return (0);
	*map = ft_get_map(ft_words_count(list->content, ' '), ft_lstcount(lst));
	if (*map == NULL)
		return (ft_mem_clean(&list, map));
	return (ft_fill_map(map, list));
}
