/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:18:47 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/18 11:02:46 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	load_images(t_all *struc)
{
	int	x;

	struc->sprites.background = mlx_xpm_file_to_image(struc->mlx,
			"graph/Background.xpm", &x, &x);
	struc->sprites.exit = mlx_xpm_file_to_image(struc->mlx,
			"graph/Exit.xpm", &x, &x);
	struc->sprites.border = mlx_xpm_file_to_image(struc->mlx,
			"graph/Border.xpm", &x, &x);
	struc->sprites.spaceship_up = mlx_xpm_file_to_image(struc->mlx,
			"graph/Spaceship_up.xpm", &x, &x);
	struc->sprites.spaceship_down = mlx_xpm_file_to_image(struc->mlx,
			"graph/Spaceship_down.xpm", &x, &x);
	struc->sprites.spaceship_left = mlx_xpm_file_to_image(struc->mlx,
			"graph/Spaceship_left.xpm", &x, &x);
	struc->sprites.spaceship_right = mlx_xpm_file_to_image(struc->mlx,
			"graph/Spaceship_right.xpm", &x, &x);
	struc->sprites.enemy = mlx_xpm_file_to_image(struc->mlx,
			"graph/Enemy.xpm", &x, &x);
	struc->sprites.collectible = mlx_xpm_file_to_image(struc->mlx,
			"graph/Collectible.xpm", &x, &x);
}
