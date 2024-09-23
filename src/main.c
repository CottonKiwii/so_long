/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:46:53 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/23 12:25:46 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	(void)ac;
	(void)av;
	ft_printf("hello world\n");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 300, 400, "yo wtf");
	while (1)
	{

	}
}

