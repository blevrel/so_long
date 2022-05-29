/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_prog.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 09:25:31 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/19 13:10:53 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	end_prog(t_all *struc)
{
	int	i;

	i = -1;
	if (struc->window.win_ptr != NULL)
		mlx_destroy_window(struc->window.mlx, struc->window.win_ptr);
	if (struc->sprites.spaceship != NULL)
		mlx_destroy_image(struc->window.mlx, struc->sprites.spaceship);
	if (struc->sprites.exit != NULL)
		mlx_destroy_image(struc->window.mlx, struc->sprites.exit);
	if (struc->sprites.background != NULL)
		mlx_destroy_image(struc->window.mlx, struc->sprites.background);
	if (struc->sprites.collectible != NULL)
		mlx_destroy_image(struc->window.mlx, struc->sprites.collectible);
	if (struc->sprites.border != NULL)
		mlx_destroy_image(struc->window.mlx, struc->sprites.border);
	if (struc->map)
	{
		while (struc->map[++i])
			free(struc->map[i]);
		free(struc->map);
	}
	if (struc->window.mlx)
		destroy_mlx_ptr(struc);
	exit(1);
}

void	destroy_mlx_ptr(t_all *struc)
{
	mlx_loop_end(struc->window.mlx);
	mlx_destroy_display(struc->window.mlx);
	free(struc->window.mlx);
}
