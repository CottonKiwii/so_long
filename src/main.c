/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:46:53 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/24 18:40:41 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_init(t_game *game)
{
	char	*map;
	int		bytes_read;

	game->fd = open(game->file, O_RDONLY);	
	if (game->fd == -1)
		return (ft_panic(game, PERR), ERR);
	map = (char *)ft_calloc(game->height + 1, sizeof(char));
	if (!map)
		return (ft_panic(game, PERR), ERR);
	bytes_read = 1;
	bytes_read = read(game->fd, map, game->height);
	if (bytes_read == -1)
		return (free(map), ft_panic(game, PERR), ERR);
	game->map = ft_split(map, '\n');
	if (!game->map)
		return (free(map), ft_panic(game, PERR), ERR);
	return (free(map), TRUE);
}

int	valid_map(t_game *game)
{
	int	i;
	char	**cpy;

	map_init(game);
	for (i = 0; game->map[i]; i++)
		ft_printf("%s\n", game->map[i]);
	i = 0;
	cpy = ft_strarrdup(game->map);
	if (!cpy)
		return (ft_panic(game, PERR), ERR);
	for (i = 0; cpy[i]; i++)
		ft_printf("%s\n", cpy[i]);
	return (TRUE);
}

int	find_map_size(t_game *game)
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
			return (ft_panic(game, PERR), ERR);
		if (c != '0' && c != '1' && c != 'C' && c != 'P' && c != 'E' && c != '\n')
			return (ft_panic(game, MAPERR), ERR);
		if (c == '\n' && !saw_nl)
		{
			game->width = game->height;
			saw_nl = 1;
		}
		game->height += bytes_read;
	}
	return (TRUE);
}

int	valid_file(t_game *game)
{
	if (!ft_strnstr(game->file, ".ber", ft_strlen(game->file)))
		return (ft_panic(game, FILERR_1), ERR);
	if (ft_strlen(game->file) < 5)
		return (ft_panic(game, FILERR_2), ERR);
	game->fd = open(game->file, O_RDONLY);	
	if (game->fd == -1)
		return (ft_panic(game, PERR), ERR);
	if (!find_map_size(game))
		return (close(game->fd), ERR);
	return (close(game->fd), TRUE);
}

void	struct_init(t_game *game, char *file)
{
	game->fd = -1;
	game->file = file;
	game->width = 0;
	game->height = 0;
	game->map = NULL;
	game->mlx = NULL;
	game->mlx_win = NULL;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_putstr_fd("Error\nInvalid arguments\n", STDERR), ERR);
	struct_init(&game, av[1]);
	if (!valid_file(&game))
		return (ERR);
	valid_map(&game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 300, 400, "so_long");
	ft_exit(&game, TRUE);
}

