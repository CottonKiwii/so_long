/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:23:42 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/29 12:50:29 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_texture(t_game *game, char tile, int y, int x)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->tex.border, x * 32, y * 32);
	if (tile == '0')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->tex.tile, x * 32, y * 32);
	if (tile == 'P')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->tex.player, x * 32, y * 32);
	if (tile == 'C')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->tex.collect, x * 32, y * 32);
	if (tile == 'E')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->tex.exit, x * 32, y * 32);
}

void	print_map(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			put_texture(game, game->map.content[y][x], y, x);
			x++;
		}
		y++;
	}
}

void	tex_init(t_game *game)
{
	int	s;

	s = 32;
	game->tex.player = mlx_xpm_file_to_image(game->mlx, TEX_CHAR, &s, &s);
	if (!game->tex.player)
		ft_panic(game, NULL);
	game->tex.collect = mlx_xpm_file_to_image(game->mlx, TEX_COLL, &s, &s);
	if (!game->tex.collect)
		ft_panic(game, NULL);
	game->tex.border = mlx_xpm_file_to_image(game->mlx, TEX_WALL, &s, &s);
	if (!game->tex.border)
		ft_panic(game, NULL);
	game->tex.tile = mlx_xpm_file_to_image(game->mlx, TEX_TILE, &s, &s);
	if (!game->tex.tile)
		ft_panic(game, NULL);
	game->tex.exit = mlx_xpm_file_to_image(game->mlx, TEX_EXIT, &s, &s);
	if (!game->tex.exit)
		ft_panic(game, NULL);
}

void	events_init(t_game *game)
{
	mlx_loop_hook(game->mlx, &hook_idle, NULL);
	mlx_key_hook(game->mlx_win, &hook_key, game);
	mlx_hook(game->mlx_win, 17, 0, &hook_close, game);
}

void	start_mlx(t_game *game)
{
	if (game->map.width * 32 > MAX_W || game->map.height * 32 > MAX_H)
		ft_panic(game, ERR_BIG);
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_panic(game, NULL);
	game->mlx_win = mlx_new_window(game->mlx, game->map.width * 32,
			game->map.height * 32, "so_long");
	if (!game->mlx_win)
		ft_panic(game, NULL);
	events_init(game);
	tex_init(game);
	print_map(game);
}
