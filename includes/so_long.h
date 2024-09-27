/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:48:20 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/27 10:27:32 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* LIBRARIES */
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

/* MACROS */
# define ERR 0
# define TRUE 1

# define ERR_SHORT "Argument too short\n"
# define ERR_FILE "Argument is not .ber\n"
# define ERR_MAP "Map contents invalid\n"

# define STDIN	STDIN_FILENO
# define STDOUT	STDOUT_FILENO
# define STDERR	STDERR_FILENO

/* STRUCTS */
typedef struct s_check
{
	int	player;
	int	exit;
	int	collect;
}	t_check;

typedef struct s_map
{
	int		width;
	int		height;
	int		len;
	char	**content;
}	t_map;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_game
{
	int			fd;
	char		*file;
	t_map		map;
	t_player	player;
	t_check		check;
	void		*mlx;
	void		*mlx_win;
}	t_game;

/* FUNCTIONS */
void	valid_chars(t_game *game, char c);
void	find_map_size(t_game *game);
void	valid_file(t_game *game);
void	struct_init(t_game *game, char *file);

void	map_init(t_game *game);
void	valid_map(t_game *game);

void	ft_panic(t_game *game, char *error);
void	ft_exit(t_game *game, int status);

#endif
