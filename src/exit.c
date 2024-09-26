/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:37:27 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/26 14:05:08 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_game *game, int status)
{
	if (game->fd != -1)
		close(game->fd);
	if (game->map.content)
		ft_free_strarr(game->map.content);	
	exit(status);
}

void	ft_panic(t_game *game, char *error)
{
	ft_putstr_fd("Error\n", STDERR);
	if (error)
		ft_putstr_fd(error, STDERR);
	else
		perror(NULL);
	ft_exit(game, ERR);	
}
