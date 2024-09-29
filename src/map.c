/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:25:09 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/29 12:04:01 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game *game, char **cpy)
{
	int	x;
	int	y;

	y = 0;
	while (!ft_strchr(cpy[y], 'P'))
		y++;
	x = 0;
	while (cpy[y] && cpy[y][x] != 'P')
		x++;
	game->player.x = x;
	game->player.y = y;
}

void	check_len(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.content[i])
	{
		if ((int)ft_strlen(game->map.content[i]) != game->map.width)
			ft_panic(game, ERR_MAP);
		i++;
	}
}

void	check_border(t_game *game)
{
	int	x;
	int	y;
	int	height;
	int width;

	check_len(game);
	y = 0;
	height = game->map.height;
	width = game->map.width;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.content[0][x] != '1' || game->map.content[height - 1][x] != '1')
				ft_panic(game, ERR_MAP);
			else if (game->map.content[y][0] != '1' || game->map.content[y][width - 1] != '1')
				ft_panic(game, ERR_MAP);
			x++;
		}
		y++;
	}
}

void	check_copy(t_game *game, char **cpy)
{
	int		x;
	int		y;

	y = 0;
	while (cpy[y])	
	{
		x = 0;
		while (cpy[y][x])
		{
			if (cpy[y][x] != '1' && cpy[y][x] != 'F' 
				&& cpy[y][x] != '0' && cpy[y][x] != 'E')
				(ft_free_strarr(cpy), ft_panic(game, ERR_MAP));
			if (cpy[y][x] == 'E' && cpy[y - 1][x] != 'F' && cpy[y + 1][x] != 'F'
				&& cpy[y][x - 1] != 'F' && cpy[y][x + 1] != 'F')
				(ft_free_strarr(cpy), ft_panic(game, ERR_MAP));
			x++;
		}
		y++;
	}
}

void	valid_map(t_game *game)
{
	char	**cpy;

	map_init(game);
	check_border(game);
	cpy = ft_strarrdup(game->map.content);
	if (!cpy)
		ft_panic(game, NULL);
	find_player(game, cpy);
	map_floodfill(game, cpy, game->player.x, game->player.y);
	check_copy(game, cpy);
	ft_free_strarr(cpy);
}
