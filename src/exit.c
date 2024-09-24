/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:37:27 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/24 15:55:58 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_game *game, t_nbr status)
{
	exit(status);
}

void	parse_error(t_game *game, t_err status)
{
	ft_putstr_fd("Error\n", STDERR);
	if (status == FILERR_1)
		ft_putstr_fd("Argument is not .ber\n", STDERR);
	if (status == FILERR_2)
		ft_putstr_fd("Argument cannot be .ber\n", STDERR);
	if (status == MAPERR)
		ft_putstr_fd("Map contents invalid\n", STDERR);
	else if (status == PERR)
		perror(NULL);
	ft_exit(game, ERR);	
}
