/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:12:27 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/19 13:11:57 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "mlx.h"
# include "structures.h"
# include "defines.h"
# include "mlx_int.h"

//open window
char	*open_window(t_all *struc);
int		get_width_size(int map, t_all *struc);
int		get_height_size(int map, t_all *struc);

//load images
void	load_images(t_all *struc);

//display sprites
void	display_background(t_all *struc);
void	choose_sprite(t_all *struc);
void	display_sprite1(t_all *struc, int element);
void	display_sprite2(t_all *struc, int element);

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

//error msg
void	disp_error_msg(t_all *struc);

//end_prog
void	end_prog(t_all *struc);
void	destroy_mlx_ptr(t_all *struc);

//init_struc
void	init_struc(t_all *struc);

#endif
