/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unknown_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blevrel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 14:57:17 by blevrel           #+#    #+#             */
/*   Updated: 2022/05/18 09:16:14 by blevrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long_bonus.h"

int	check_unknown_char(t_all *struc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (struc->map[j])
	{
		i = 0;
		while (struc->map[j][i])
		{
			if (struc->map[j][i] != 'P' && struc->map[j][i] != 'E'
				&& struc->map[j][i] != '0' && struc->map[j][i] != '1'
				&& struc->map[j][i] != 'C' && struc->map[j][i] != 'N')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
