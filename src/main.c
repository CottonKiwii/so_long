/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:46:53 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/23 14:09:50 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid(char *file)
{
	int	fd;

	if (!ft_strnstr(file, ".ber", ft_strlen(file)))
		return (ft_putstr_fd("so_long: argument is not .ber\n", STDERR), ERR);
	fd = open(file, O_RDONLY);	
	if (fd == -1)
		return (perror("so_long"), ERR);
	return (TRUE);
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;

	if (ac != 2)
		return (ft_putstr_fd("so_long: invalid arguments\n", STDERR), ERR);
	if (!is_valid(av[1]))
		return (ERR);		
	ft_printf("hello world\n");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 300, 400, "so_long");
}

