/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:25:09 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/26 19:06:40 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_init(t_game *game)
{
	char	*map;
	int		bytes_read;

	game->fd = open(game->file, O_RDONLY);	
	if (game->fd == -1)
		return (ft_panic(game, NULL), ERR);
	map = (char *)ft_calloc(game->map.len + 1, sizeof(char));
	if (!map)
		return (ft_panic(game, NULL), ERR);
	bytes_read = read(game->fd, map, game->map.len);
	if (bytes_read == -1)
		return (free(map), ft_panic(game, NULL), ERR);
	game->map.content = ft_split(map, '\n');
	if (!game->map.content)
		return (free(map), ft_panic(game, NULL), ERR);
	game->map.height = ft_strarrlen(game->map.content);
	return (free(map), TRUE);
}

void	map_floodfill(t_game *game, char **cpy, int x, int y)
{
	if (cpy[y][x] == '1' || cpy[y][x] == 'F')	
		return ;
	cpy[y][x] = 'F';
	map_floodfill(game, cpy, x, y - 1);
	map_floodfill(game, cpy, x, y + 1);
	map_floodfill(game, cpy, x - 1, y);
	map_floodfill(game, cpy, x + 1, y);
}

int	find_player(t_game *game, char **cpy)
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
	return (TRUE);
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

int	valid_map(t_game *game)
{
	int	x;
	int	y;
	char	**cpy;

	map_init(game);
	check_border(game);
	cpy = ft_strarrdup(game->map.content);
	if (!cpy)
		return (ft_panic(game, NULL), ERR);
	find_player(game, cpy);
	map_floodfill(game, cpy, game->player.x, game->player.y);
	y = 0;
	while (cpy[y])	
	{
		x = 0;
		while (cpy[y][x])
		{
			if (cpy[y][x] != '1' && cpy[y][x] != 'F')
				ft_panic(game, ERR_MAP);
			x++;
		}
		y++;
	}
	ft_free_strarr(cpy);
	return (TRUE);
}
