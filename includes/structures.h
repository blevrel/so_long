/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 17:50:53 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/17 14:43:13 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "so_long.h"

typedef struct s_sprites
{
	void	*spaceship;
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
	void	*mlx;
	int		x;
	int		y;
}				t_window;

typedef struct s_all
{
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
