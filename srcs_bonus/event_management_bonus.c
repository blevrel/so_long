/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:32:56 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/18 10:59:00 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	close_win_cross(t_all *struc)
{
	end_prog(struc);
	return (0);
}

void	collect_and_open_exit(t_all *struc)
{
	if (struc->map[struc->player.y][struc->player.x] == 'C')
	{
		struc->map[struc->player.y][struc->player.x] = '0';
		struc->player.collected++;
	}
	else if (struc->map[struc->player.y][struc->player.x] == 'E' &&
			struc->player.collected == struc->env.collectibles)
	{
		struc->map[struc->player.y][struc->player.x] = '0';
		ft_printf("Bien joué !\n");
		end_prog(struc);
	}
}

int	allow_move(t_all *struc, int key)
{
	if (key == XK_w || key == XK_a || key == XK_s || key == XK_d)
	{
		if (struc->map[struc->player.y][struc->player.x] != '1'
			&& struc->map[struc->player.y][struc->player.x] != 'E')
		{
			if (struc->map[struc->player.y][struc->player.x] == 'C')
				collect_and_open_exit(struc);
			else if (struc->map[struc->player.y][struc->player.x] == 'N')
				die_to_enemy(struc);
			return (1);
		}
		else if (struc->map[struc->player.y][struc->player.x] == 'E')
			collect_and_open_exit(struc);
	}
	if (key == XK_w)
		struc->player.y++;
	else if (key == XK_a)
		struc->player.x++;
	else if (key == XK_s)
		struc->player.y--;
	else if (key == XK_d)
		struc->player.x--;
	return (0);
}

int	keypress(int keycode, t_all *struc)
{
	if (keycode == XK_Escape)
		end_prog(struc);
	if (keycode == XK_w)
		struc->player.y--;
	else if (keycode == XK_a)
		struc->player.x--;
	else if (keycode == XK_s)
		struc->player.y++;
	else if (keycode == XK_d)
		struc->player.x++;
	if (allow_move(struc, keycode) == 1)
	{
		display_background(struc);
		choose_sprite(struc, keycode);
	}
	return (0);
}

void	event_manager(t_all *struc)
{
	mlx_hook(struc->window.win_ptr, DestroyNotify, StructureNotifyMask,
		close_win_cross, struc);
	mlx_hook(struc->window.win_ptr, KeyPress, KeyPressMask,
		keypress, struc);
}
