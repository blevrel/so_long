/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:44:45 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/19 13:31:11 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

void	init_struc(t_all *struc)
{
	struc->error.borders = 0;
	struc->error.content = 0;
	struc->error.name = 0;
	struc->error.unknown_char = 0;
	struc->error.error = 0;
	struc->position.x = 0;
	struc->position.y = 0;
	struc->player.x = 0;
	struc->player.y = 0;
	struc->player.count = 0;
	struc->player.collected = 0;
	struc->env.collectibles = 0;
	struc->env.exit = 0;
	struc->env.spaceship = 0;
	struc->env.spawn_count = 0;
	struc->window.x = 0;
	struc->window.y = 0;
	init_struc2(struc);
}

void	init_struc2(t_all *struc)
{
	struc->window.win_ptr = NULL;
	struc->sprites.spaceship_up = NULL;
	struc->sprites.spaceship_down = NULL;
	struc->sprites.spaceship_left = NULL;
	struc->sprites.spaceship_right = NULL;
	struc->sprites.enemy = NULL;
	struc->sprites.exit = NULL;
	struc->sprites.background = NULL;
	struc->sprites.collectible = NULL;
	struc->sprites.border = NULL;
	struc->map = NULL;
}
