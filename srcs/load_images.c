/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:18:47 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/19 10:52:50 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	load_images(t_all *struc)
{
	int	x;

	struc->sprites.background = mlx_xpm_file_to_image(struc->window.mlx,
			"graph/Background.xpm", &x, &x);
	struc->sprites.exit = mlx_xpm_file_to_image(struc->window.mlx,
			"graph/Exit.xpm", &x, &x);
	struc->sprites.border = mlx_xpm_file_to_image(struc->window.mlx,
			"graph/Border.xpm", &x, &x);
	struc->sprites.spaceship = mlx_xpm_file_to_image(struc->window.mlx,
			"graph/Spaceship_up.xpm", &x, &x);
	struc->sprites.collectible = mlx_xpm_file_to_image(struc->window.mlx,
			"graph/Collectible.xpm", &x, &x);
}
