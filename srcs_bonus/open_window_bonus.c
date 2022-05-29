/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:13:52 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/19 13:28:03 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

char	*open_window(t_all *struc)
{
	struc->window.win_ptr = mlx_new_window(struc->mlx,
			struc->window.width, struc->window.height, "Space invaders v2");
	display_background(struc);
	return (struc->window.win_ptr);
}

int	get_width_size(int map, t_all *struc)
{
	char		*line;
	size_t		count;

	count = 0;
	line = get_next_line(map, 1);
	if (!line)
	{
		end_prog(struc);
		exit(0);
	}
	count = ft_strlen(line) - 1;
	free(line);
	return (count * 16);
}

int	get_height_size(int map, t_all *struc)
{
	char		*line;
	size_t		count;

	count = 0;
	line = get_next_line(map, 1);
	if (!line)
	{
		end_prog(struc);
		exit(1);
	}
	if (line)
	{
		count++;
		free(line);
	}
	while (line)
	{
		line = get_next_line(map, 1);
		count++;
		free(line);
	}
	return (count * 16);
}
