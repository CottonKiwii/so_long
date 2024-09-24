/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:48:20 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/24 16:41:34 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

# define ERR 0
# define TRUE 1

typedef enum e_err
{
	PERR,
	MAPERR,
	FILERR_1,
	FILERR_2
}	t_err;

# define STDIN	STDIN_FILENO
# define STDOUT	STDOUT_FILENO
# define STDERR	STDERR_FILENO

typedef struct s_game
{
	int		fd;
	int		width;
	int		height;
	void	*mlx;
	void	*mlx_win;
	char	*file;
	char	**map;
}	t_game;

void	ft_panic(t_game *game, t_err status);
void	ft_exit(t_game *game, int status);

#endif
