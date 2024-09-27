/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:36:03 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/27 14:55:25 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_game *game)
{
	char	*map;
	int		bytes_read;

	game->fd = open(game->file, O_RDONLY);	
	if (game->fd == -1)
		ft_panic(game, NULL);
	map = (char *)ft_calloc(game->map.len + 1, sizeof(char));
	if (!map)
		ft_panic(game, NULL);
	bytes_read = read(game->fd, map, game->map.len);
	if (bytes_read == -1)
		(free(map), ft_panic(game, NULL), ERR);
	game->map.content = ft_split(map, '\n');
	if (!game->map.content)
		free(map), ft_panic(game, NULL);
	game->map.height = ft_strarrlen(game->map.content);
	free(map);
}

void	valid_chars(t_game *game, char c)
{
	if (c == 'C')
		game->check.collect++;
	else if (c == 'P')
		game->check.player++;
	else if (c == 'E')
		game->check.exit++;
	if (game->check.exit > 1 || game->check.player > 1)
		ft_panic(game, ERR_MAP);
}

void	find_map_size(t_game *game)
{
	int		bytes_read;
	int		saw_nl;
	char	c;

	bytes_read = 1;
	saw_nl = 0;
	while (bytes_read)
	{
		bytes_read = read(game->fd, &c, 1);
		if (bytes_read == -1)
			ft_panic(game, NULL);
		if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E' && c != '\n')
			ft_panic(game, ERR_MAP);
		valid_chars(game, c);
		if (c == '\n' && !saw_nl)
		{
			game->map.width = game->map.len;
			saw_nl = 1;
		}
		game->map.len += bytes_read;
	}
	if (!game->check.collect || !game->check.exit || !game->check.player)
		ft_panic(game, ERR_MAP);
}

void	valid_file(t_game *game)
{
	int	i;

	if (ft_strlen(game->file) < 5)
		ft_panic(game, ERR_SHORT);
	i = ft_strlen(game->file) - 4;
	if (ft_strncmp(&game->file[i], ".ber", 4))
		ft_panic(game, ERR_FILE);
	game->fd = open(game->file, O_RDONLY);	
	if (game->fd == -1)
		ft_panic(game, NULL);
	find_map_size(game);
	close(game->fd);
}

void	struct_init(t_game *game, char *file)
{
	game->fd = -1;
	game->file = file;
	game->map.width = 0;
	game->map.height = 0;
	game->map.len = 0;
	game->map.content = NULL;
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->check.player = 0;
	game->check.exit = 0;
	game->check.collect = 0;
	game->check.steps = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->tex.player = 0;
	game->tex.collect = 0;
	game->tex.border = 0;
	game->tex.tile = 0;
	game->tex.exit = 0;
}
