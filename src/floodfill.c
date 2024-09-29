/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:56:47 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/29 11:57:01 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_floodfill(t_game *game, char **cpy, int x, int y)
{
	if (cpy[y][x] == '1' || cpy[y][x] == 'F' || cpy[y][x] == 'E')
		return ;
	cpy[y][x] = 'F';
	map_floodfill(game, cpy, x, y - 1);
	map_floodfill(game, cpy, x, y + 1);
	map_floodfill(game, cpy, x - 1, y);
	map_floodfill(game, cpy, x + 1, y);
}

