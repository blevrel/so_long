/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 09:58:16 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/19 13:04:40 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	parse_and_display_map(t_all *struc, int fd, char *map_file)
{
	init_struc(struc);
	struc->window.width = get_width_size(fd, struc);
	struc->window.height = get_height_size(fd, struc);
	close(fd);
	fd = open(map_file, O_RDONLY);
	struc->map = fill_matrix(fd, struc);
	close(fd);
	if (struc->map == NULL || check_map(struc) == 1)
		return (struc->error.error = 1);
	load_images(struc);
	struc->window.win_ptr = open_window(struc);
	choose_sprite(struc);
	return (0);
}

int	main(int argc, char **argv)
{
	t_all	struc;
	int		fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error while opening fd");
		return (0);
	}
	struc.map_name = argv[1];
	struc.window.mlx = mlx_init();
	parse_and_display_map(&struc, fd, argv[1]);
	if (struc.error.error == 1)
	{
		disp_error_msg(&struc);
		end_prog(&struc);
		return (0);
	}
	event_manager(&struc);
	mlx_loop(struc.window.mlx);
	return (0);
}
