/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:01:31 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/18 09:25:03 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	display_background(t_all *struc)
{
	struc->window.x = 0;
	struc->window.y = 0;
	while (struc->window.y * BACKGROUND_RES < struc->window.height)
	{
		struc->position.x = 0;
		while (struc->window.x * BACKGROUND_RES < struc->window.width)
		{
			mlx_put_image_to_window(struc->mlx, struc->window.win_ptr,
				struc->sprites.background, struc->window.x * BACKGROUND_RES,
				struc->window.y * BACKGROUND_RES);
			struc->window.x++;
		}
		struc->window.y++;
	}
}

void	display_rotating_spaceship(t_all *struc, int keycode)
{
	if (keycode == XK_w)
	{
		mlx_put_image_to_window(struc->mlx, struc->window.win_ptr,
			struc->sprites.spaceship_up, struc->player.x * RES,
			struc->player.y * RES);
	}
	else if (keycode == XK_s)
	{
		mlx_put_image_to_window(struc->mlx, struc->window.win_ptr,
			struc->sprites.spaceship_down, struc->player.x * RES,
			struc->player.y * RES);
	}
	else if (keycode == XK_a)
	{
		mlx_put_image_to_window(struc->mlx, struc->window.win_ptr,
			struc->sprites.spaceship_left, struc->player.x * RES,
			struc->player.y * RES);
	}
	else if (keycode == XK_d)
	{
		mlx_put_image_to_window(struc->mlx, struc->window.win_ptr,
			struc->sprites.spaceship_right, struc->player.x * RES,
			struc->player.y * RES);
	}
	disp_moves_in_window(struc);
}

void	display_sprite(t_all *struc, int element)
{	
	if (element == EXIT)
	{
		mlx_put_image_to_window(struc->mlx, struc->window.win_ptr,
			struc->sprites.exit, struc->position.x * RES,
			struc->position.y * RES);
	}
	else if (element == BORDER)
	{
		mlx_put_image_to_window(struc->mlx, struc->window.win_ptr,
			struc->sprites.border, struc->position.x * RES,
			struc->position.y * RES);
	}
	else if (element == COLLECTIBLE)
	{
		mlx_put_image_to_window(struc->mlx, struc->window.win_ptr,
			struc->sprites.collectible, struc->position.x * RES,
			struc->position.y * RES);
	}
}

void	choose_sprite(t_all *struc, int keypress)
{
	struc->position.y = -1;
	while (++struc->position.y * RES < struc->window.height)
	{
		struc->position.x = -1;
		while (++struc->position.x * RES < struc->window.width)
		{
			if (struc->map[struc->position.y][struc->position.x] == 'P')
			{
				if (struc->player.count == 0)
				{
					struc->player.x = struc->position.x;
					struc->player.y = struc->position.y;
				}
				display_rotating_spaceship(struc, keypress);
			}
			else if (struc->map[struc->position.y][struc->position.x] == 'C')
				display_sprite(struc, COLLECTIBLE);
			else if (struc->map[struc->position.y][struc->position.x] == 'E')
				display_sprite(struc, EXIT);
			else if (struc->map[struc->position.y][struc->position.x] == '1')
				display_sprite(struc, BORDER);
			else if (struc->map[struc->position.y][struc->position.x] == 'N')
				display_enemy(struc);
		}
	}
}
