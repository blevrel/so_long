/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:44:45 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/19 13:13:04 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	init_struc(t_all *struc)
{
	struc->sprites.spaceship = NULL;
	struc->sprites.exit = NULL;
	struc->sprites.background = NULL;
	struc->sprites.collectible = NULL;
	struc->sprites.border = NULL;
	struc->map = NULL;
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
	struc->window.win_ptr = NULL;
	struc->window.x = 0;
	struc->window.y = 0;
}
