/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:26:09 by opodolia          #+#    #+#             */
/*   Updated: 2017/03/23 11:24:22 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*res;

	if (!(res = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (content)
	{
		if ((res->content = malloc(content_size)))
		{
			ft_memcpy(res->content, content, content_size);
			res->content_size = content_size;
		}
	}
	else
	{
		res->content = 0;
		res->content_size = 0;
	}
	res->next = 0;
	return (res);
}
