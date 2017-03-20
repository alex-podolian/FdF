#include "libft.h"

int		ft_split_del(char ***split)
{
	int		i;
	char	**str;

	i = 0;
	str = *split;
	while (*str)
	{
		ft_strdel(str);
		str = &(*split)[++i];
	}
	ft_memdel((void **)split);
	return (0);
}
