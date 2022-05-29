/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:46:34 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/16 17:37:24 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	**fill_matrix(int fd, t_all *struc)
{
	char		**mat;
	int			i;
	char		*str;
	int			j;

	i = -1;
	j = 0;
	mat = ft_calloc((struc->window.height / 16) + 1, sizeof(char *));
	while (++i < (struc->window.height / 16))
		mat[i] = ft_calloc((struc->window.width / 16) + 1, sizeof(char));
	while (j < struc->window.height / 16)
	{
		str = get_next_line(fd, 1);
		if (check_rectangle(str, struc) == 1)
		{
			ft_free(mat, str);
			return (NULL);
		}
		i = -1;
		while (++i < struc->window.width / 16 && str[i] != '\n')
			mat[j][i] = fill(struc, str[i]);
		j++;
		free(str);
	}
	return (mat);
}

char	fill(t_all *struc, char c)
{
	if (c == 'P' && struc->env.spawn_count == 0)
		struc->env.spawn_count = 1;
	else if (c == 'P' && struc->env.spawn_count == 1)
		return ('0');
	return (c);
}

void	ft_free(char **mat, char *str)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(str);
	free(mat);
}
