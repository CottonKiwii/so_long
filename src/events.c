/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:23:21 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/29 11:26:01 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hook_idle(void *ptr)
{
	(void) ptr;
	return (0);
}

int	hook_close(t_game *game)
{
	ft_exit(game, 0);
	return (0);
}

int	hook_key(int key, t_game *game)
{
	if (key == 65307)
		ft_exit(game, 0);
	if (key == 'w' || key == 65362 || key == 'k')
		move_up(game);
	if (key == 'a' || key == 65361 || key == 'h')
		move_left(game);
	if (key == 'd' || key == 65363 || key == 'l')
		move_right(game);
	if (key == 's' || key == 65364 || key == 'j')
		move_down(game);
	return (0);
}
