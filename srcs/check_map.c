/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:19:08 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/16 17:41:15 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	check_rectangle(char *str, t_all *struc)
{
	size_t	line_len;

	line_len = struc->window.width / 16;
	if (str == NULL)
		return (0);
	if (ft_strlen(str) - 1 != line_len)
		return (1);
	return (0);
}

int	check_borders(t_all *struc)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < struc->window.width / 16)
	{
		if (struc->map[0][x] != '1')
			return (1);
		if (struc->map[(struc->window.height / 16) - 1][x] != '1')
			return (1);
		x++;
	}
	while (y < struc->window.height / 16)
	{
		if (struc->map[y][0] != '1')
			return (1);
		if (struc->map[y][(struc->window.width / 16) - 1] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	check_content(t_all *struc)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (struc->map[y])
	{
		x = 0;
		while (struc->map[y][x])
		{
			if (struc->map[y][x] == 'C')
				struc->env.collectibles++;
			if (struc->map[y][x] == 'E')
				struc->env.exit++;
			if (struc->map[y][x] == 'P')
				struc->env.spaceship++;
			x++;
		}
		y++;
	}
	if (struc->env.collectibles > 0 && struc->env.exit > 0
		&& struc->env.spaceship > 0)
		return (0);
	return (1);
}

int	check_name(t_all *struc)
{
	char	*to_find;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(struc->map_name) - 1;
	to_find = "reb.";
	while (to_find[i])
	{
		if (struc->map_name[j] != to_find[i])
			return (1);
		i++;
		j--;
	}
	return (0);
}

int	check_map(t_all *struc)
{
	if (check_borders(struc) == 1)
	{
		struc->error.borders++;
		return (1);
	}
	if (check_content(struc) == 1)
	{
		struc->error.content++;
		return (1);
	}
	if (check_name(struc) == 1)
	{
		struc->error.name++;
		return (1);
	}
	if (check_unknown_char(struc) == 1)
	{
		struc->error.unknown_char++;
		return (1);
	}
	return (0);
}
