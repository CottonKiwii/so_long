/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:46:53 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/26 14:18:31 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_putstr_fd("Error\nInvalid arguments\n", STDERR), ERR);
	struct_init(&game, av[1]);
	valid_file(&game);
	valid_map(&game);
	/*game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 300, 400, "so_long");*/
	ft_exit(&game, TRUE);
}

