/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:46:53 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/23 17:48:01 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_height(t_game *game)
{
	int		fd;
	char	*str;

	fd = open(game->file, O_RDONLY);
	if (fd == -1)
		return ;
	str = "";
	while (str)
	{
		str = get_next_line(fd);
		game->height++;
		free(str);
	}
	close(fd);
}

int	valid_map(t_game *game)
{
	int	i;

	(void) game;
	i = 0;
	return (TRUE);
}

int	find_map_size(t_game *game)
{
	char	*tmp;

	tmp = get_next_line(game->fd);
	if (!tmp)
		return (ERR);
	game->width = ft_strlen(tmp);	
	game->height = 0;
	find_height(game);
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
	if (!find_map_size(game))
		return (perror("so_long"), ERR);
	return (TRUE);
}

void	struct_init(t_game *game, char *file)
{
	game->fd = -1;
	game->file = file;
	game->width = 0;
	game->map = NULL;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_putstr_fd("so_long: invalid arguments\n", STDERR), ERR);
	struct_init(&game, av[1]);
	if (!valid_file(&game, av[1]))
		return (close(game.fd), ERR);
	if (!valid_map(&game))		
		return (close(game.fd), ERR);
	ft_printf("Height is %d\n", game.height);
	ft_printf("Width is %d\n", game.width);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 300, 400, "so_long");
}

