/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:37:27 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/29 12:37:58 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_game(t_game *game)
{
	if (game->tex.player)
		mlx_destroy_image(game->mlx, game->tex.player);
	if (game->tex.collect)
		mlx_destroy_image(game->mlx, game->tex.collect);
	if (game->tex.border)
		mlx_destroy_image(game->mlx, game->tex.border);
	if (game->tex.tile)
		mlx_destroy_image(game->mlx, game->tex.tile);
	if (game->tex.exit)
		mlx_destroy_image(game->mlx, game->tex.exit);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	ft_exit(t_game *game, int status)
{
	if (game->fd != -1)
		close(game->fd);
	if (game->map.content)
		ft_free_strarr(game->map.content);
	if (game->mlx)
		ft_free_game(game);
	exit(status);
}

void	ft_win(t_game *game)
{
	ft_printf("         YOU WON!		\n");
	ft_printf("--------------------------\n");
	ft_printf("   It took you %d steps   \n", game->check.steps);
	ft_printf("--------------------------\n");
	ft_exit(game, 0);
}

void	ft_panic(t_game *game, char *error)
{
	ft_putstr_fd("Error\n", STDERR);
	if (error)
		ft_putstr_fd(error, STDERR);
	else
		perror(NULL);
	ft_exit(game, 1);
}
