/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_error_msg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:04:42 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/15 15:28:57 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	disp_error_msg(t_all *struc)
{
	if (struc->map != NULL && check_borders(struc) > 0)
		ft_printf("Error\nInvalid map. Map must be closed by borders");
	else if (struc->map != NULL && struc->error.content > 0)
		ft_printf("Error\nInvalid content. Need 1 spawn, 1 item and 1 exit");
	else if (struc->map != NULL && struc->error.name > 0)
		ft_printf("Error\nInvalid file name. File must end with '.ber'");
	else if (struc->map != NULL && struc->error.unknown_char > 0)
		ft_printf("Error\nInvalid character in map");
	else
		ft_printf("Error\nInvalid map. Map must be a rectangle");
	return ;
}
