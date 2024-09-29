/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:41:39 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/29 11:30:28 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	process_move(t_game *game, int y, int x)
{
	if (game->map.content[y][x] == '1')
		return (FALSE);
	if (game->map.content[y][x] == 'E' && game->check.collect)
		return (FALSE);
	if (game->map.content[y][x] == 'E' && !game->check.collect)
	{
		game->map.content[y][x] = 'P';
		game->map.content[game->player.y][game->player.x] = '0';
		ft_win(game);
	}
	if (game->map.content[y][x] == 'C')
		return (game->check.collect--, TRUE);
	return (TRUE);
}

void	move_up(t_game *game)
{
	if (!process_move(game, game->player.y - 1, game->player.x))
		return ;
	game->map.content[game->player.y - 1][game->player.x] = 'P';
	game->map.content[game->player.y][game->player.x] = '0';
	game->player.y--;
	print_map(game);
	game->check.steps++;
	ft_printf("STEPS: %d\n", game->check.steps);
}

void	move_left(t_game *game)
{
	if (!process_move(game, game->player.y, game->player.x - 1))
		return ;
	game->map.content[game->player.y][game->player.x - 1] = 'P';
	game->map.content[game->player.y][game->player.x] = '0';
	game->player.x--;
	print_map(game);
	game->check.steps++;
	ft_printf("STEPS: %d\n", game->check.steps);
}

void	move_right(t_game *game)
{
	if (!process_move(game, game->player.y, game->player.x + 1))
		return ;
	game->map.content[game->player.y][game->player.x + 1] = 'P';
	game->map.content[game->player.y][game->player.x] = '0';
	game->player.x++;
	print_map(game);
	game->check.steps++;
	ft_printf("STEPS: %d\n", game->check.steps);
}

void	move_down(t_game *game)
{
	if (!process_move(game, game->player.y + 1, game->player.x))
		return ;
	game->map.content[game->player.y + 1][game->player.x] = 'P';
	game->map.content[game->player.y][game->player.x] = '0';
	game->player.y++;
	print_map(game);
	game->check.steps++;
	ft_printf("STEPS: %d\n", game->check.steps);
}
