/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 08:50:32 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/19 10:18:48 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	die_to_enemy(t_all *struc)
{
	struc->map[struc->player.y][struc->player.x] = '0';
	ft_printf("You are dead :'(");
	end_prog(struc);
}

void	display_enemy(t_all *struc)
{
	mlx_put_image_to_window(struc->mlx, struc->window.win_ptr,
		struc->sprites.enemy, struc->position.x * RES,
		struc->position.y * RES);
}
