/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:50:53 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/19 10:19:29 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCTURES_BONUS_H
# define STRUCTURES_BONUS_H
# include "so_long_bonus.h"

typedef struct s_sprites
{
	void	*spaceship_up;
	void	*spaceship_down;
	void	*spaceship_left;
	void	*spaceship_right;
	void	*enemy;
	void	*exit;
	void	*background;
	void	*collectible;
	void	*border;
}				t_sprites;

typedef struct s_error
{
	int	borders;
	int	content;
	int	name;
	int	unknown_char;
	int	error;
}				t_error;

typedef struct s_position
{
	int	x;
	int	y;
}				t_position;

typedef struct s_player
{
	int	x;
	int	y;
	int	count;
	int	collected;
}				t_player;

typedef struct s_env
{
	int	collectibles;
	int	exit;
	int	spaceship;
	int	spawn_count;
}				t_env;

typedef struct s_window
{
	int		width;
	int		height;
	void	*win_ptr;
	int		x;
	int		y;
}				t_window;

typedef struct s_all
{
	void		*mlx;
	char		**map;
	char		*map_name;
	t_sprites	sprites;
	t_position	position;
	t_window	window;
	t_player	player;
	t_env		env;
	t_error		error;
}				t_all;

#endif
