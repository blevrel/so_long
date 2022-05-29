/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_prog_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:25:31 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/19 13:22:19 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	end_prog(t_all *struc)
{
	int	i;

	i = -1;
	if (struc->window.win_ptr != NULL)
		mlx_destroy_window(struc->mlx, struc->window.win_ptr);
	destroy_images(struc);
	if (struc->map)
	{
		while (struc->map[++i])
			free(struc->map[i]);
		free(struc->map);
	}
	if (struc->mlx)
	{
		mlx_loop_end(struc->mlx);
		mlx_destroy_display(struc->mlx);
		free(struc->mlx);
	}
	exit(0);
}

void	destroy_images(t_all *struc)
{
	if (struc->sprites.spaceship_up != NULL)
		mlx_destroy_image(struc->mlx, struc->sprites.spaceship_up);
	if (struc->sprites.spaceship_down != NULL)
		mlx_destroy_image(struc->mlx, struc->sprites.spaceship_down);
	if (struc->sprites.spaceship_left != NULL)
		mlx_destroy_image(struc->mlx, struc->sprites.spaceship_left);
	if (struc->sprites.spaceship_right != NULL)
		mlx_destroy_image(struc->mlx, struc->sprites.spaceship_right);
	if (struc->sprites.exit != NULL)
		mlx_destroy_image(struc->mlx, struc->sprites.exit);
	if (struc->sprites.background != NULL)
		mlx_destroy_image(struc->mlx, struc->sprites.background);
	if (struc->sprites.collectible != NULL)
		mlx_destroy_image(struc->mlx, struc->sprites.collectible);
	if (struc->sprites.border != NULL)
		mlx_destroy_image(struc->mlx, struc->sprites.border);
	if (struc->sprites.enemy != NULL)
		mlx_destroy_image(struc->mlx, struc->sprites.enemy);
}
