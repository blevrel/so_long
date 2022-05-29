/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:12:27 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/19 13:29:47 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "libft.h"
# include "mlx.h"
# include "structures_bonus.h"
# include "defines_bonus.h"
# include "mlx_int.h"

//open window
char	*open_window(t_all *struc);
int		get_width_size(int map, t_all *struc);
int		get_height_size(int map, t_all *struc);

//load images
void	load_images(t_all *struc);

//display sprites
void	display_background(t_all *struc);
void	choose_sprite(t_all *struc, int keypress);
void	display_sprite1(t_all *struc, int element);
void	display_sprite2(t_all *struc, int element);
void	display_rotating_spaceship(t_all *struc, int keycode);

//manage event
void	event_manager(t_all *struc);
int		close_win_cross(t_all *struc);
void	collect_and_open_exit(t_all *struc);
int		allow_move(t_all *struc, int keycode);
int		keypress(int keycode, t_all *struc);

//fill matrix
char	**fill_matrix(int fd, t_all *struc);
char	fill(t_all *struc, char c);
void	ft_free(char **mat, char *str);

//parse_and_display_map
int		parse_and_display_map(t_all *struc, int fd, char *map);

//check_map
int		check_borders(t_all *struc);
int		check_rectangle(char *str, t_all *struc);
int		check_content(t_all *struc);
int		check_map(t_all *struc);
int		check_name(t_all *struc);
int		check_unknown_char(t_all *struc);

//disp msg
void	disp_error_msg(t_all *struc);
void	disp_moves_in_window(t_all *struc);

//end_prog
void	end_prog(t_all *struc);
void	destroy_images(t_all *struc);

//init_struc
void	init_struc(t_all *struc);
void	init_struc2(t_all *struc);

//ennemies
void	die_to_enemy(t_all *struc);
void	display_enemy(t_all *struc);
void	move_ennemies(t_all *struc);

#endif
