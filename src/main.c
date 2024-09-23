/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:46:53 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/23 15:55:44 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_len(t_game *game)
{
	int	fd;
}

int	valid_map(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = find_len(t_game *game);
	return (TRUE);
}

int	find_buffer(t_game *game)
{
	char	*tmp;

	tmp = get_next_line(game->fd);
	if (!tmp)
		return (ERR);
	game->tmp = tmp;
	game->buffer = ft_strlen(game->tmp);	
	return (TRUE);
}

int	valid_file(t_game *game, char *file)
{
	if (!ft_strnstr(file, ".ber", ft_strlen(file)))
		return (ft_putstr_fd("so_long: argument is not .ber\n", STDERR), ERR);
	if (ft_strlen(file) < 5)
		return (ft_putstr_fd("so_long: argument is only .ber\n", STDERR), ERR);
	game->fd = open(file, O_RDONLY);	
	if (game->fd == -1)
		return (perror("so_long"), ERR);
	if (!find_buffer(game))
		return (perror("so_long"), ERR);
	return (TRUE);
}

void	struct_init(t_game *game)
{
	game->fd = -1;
	game->buffer = 0;
	game->map = NULL;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_putstr_fd("so_long: invalid arguments\n", STDERR), ERR);
	struct_init(&game);
	if (!valid_file(&game, av[1]))
		return (close(game.fd), ERR);
	if (!valid_map(&game))		
		return (close(game.fd), ERR);
	ft_printf("%s", game.tmp);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 300, 400, "so_long");
}

