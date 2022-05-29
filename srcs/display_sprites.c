/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:01:31 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/14 10:50:58 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	display_background(t_all *struc)
{
	struc->window.x = 0;
	struc->window.y = 0;
	while (struc->window.y * BACKGROUND_RES < struc->window.height)
	{
		struc->position.x = 0;
		while (struc->window.x * BACKGROUND_RES < struc->window.width)
		{
			mlx_put_image_to_window(struc->window.mlx, struc->window.win_ptr,
				struc->sprites.background, struc->window.x * BACKGROUND_RES,
				struc->window.y * BACKGROUND_RES);
			struc->window.x++;
		}
		struc->window.y++;
	}
}

void	display_sprite1(t_all *struc, int element)
{
	if (element == SPACESHIP)
	{
		mlx_put_image_to_window(struc->window.mlx, struc->window.win_ptr,
			struc->sprites.spaceship, struc->player.x * RES,
			struc->player.y * RES);
		ft_printf("You have moved %d times\n", struc->player.count);
		struc->player.count++;
	}
	else if (element == COLLECTIBLE)
	{
		mlx_put_image_to_window(struc->window.mlx, struc->window.win_ptr,
			struc->sprites.collectible, struc->position.x * RES,
			struc->position.y * RES);
	}
}

void	display_sprite2(t_all *struc, int element)
{	
	if (element == EXIT)
	{
		mlx_put_image_to_window(struc->window.mlx, struc->window.win_ptr,
			struc->sprites.exit, struc->position.x * RES,
			struc->position.y * RES);
	}
	else if (element == BORDER)
	{
		mlx_put_image_to_window(struc->window.mlx, struc->window.win_ptr,
			struc->sprites.border, struc->position.x * RES,
			struc->position.y * RES);
	}
}

void	choose_sprite(t_all *struc)
{
	struc->position.y = 0;
	while (struc->position.y * RES < struc->window.height)
	{
		struc->position.x = 0;
		while (struc->position.x * RES < struc->window.width)
		{
			if (struc->map[struc->position.y][struc->position.x] == 'P')
			{
				if (struc->player.count == 0)
				{
					struc->player.x = struc->position.x;
					struc->player.y = struc->position.y;
				}
				display_sprite1(struc, SPACESHIP);
			}
			else if (struc->map[struc->position.y][struc->position.x] == 'C')
				display_sprite1(struc, COLLECTIBLE);
			else if (struc->map[struc->position.y][struc->position.x] == 'E')
				display_sprite2(struc, EXIT);
			else if (struc->map[struc->position.y][struc->position.x] == '1')
				display_sprite2(struc, BORDER);
			struc->position.x++;
		}
		struc->position.y++;
	}
}
