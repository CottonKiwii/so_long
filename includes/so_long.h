/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:48:20 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/30 09:39:01 by jwolfram         ###   ########.fr       */
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
# define FALSE 0
# define TRUE 1

# define ERR_SHORT "Argument too short\n"
# define ERR_FILE "Argument is not .ber\n"
# define ERR_MAP "Map contents invalid\n"
# define ERR_BIG "Map size too big\n"

# define TEX_CHAR "textures/Char_2x.xpm"
# define TEX_COLL "textures/Milk_2x.xpm"
# define TEX_WALL "textures/Water_2x.xpm"
# define TEX_TILE "textures/Grass_2x.xpm"
# define TEX_EXIT "textures/Door_2x.xpm"

# define STDIN	STDIN_FILENO
# define STDOUT	STDOUT_FILENO
# define STDERR	STDERR_FILENO

# define MAX_W 1920
# define MAX_H 1080

/* STRUCTS */
typedef struct s_check
{
	int	player;
	int	exit;
	int	collect;
	int	steps;
}	t_check;

typedef struct s_texture
{
	void	*border;
	void	*player;
	void	*tile;
	void	*collect;
	void	*exit;
}	t_texture;

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
	t_texture	tex;
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
void	map_floodfill(t_game *game, char **cpy, int x, int y);

void	put_texture(t_game *game, char tile, int y, int x);
void	print_map(t_game *game);
void	tex_init(t_game *game);
void	events_init(t_game *game);
void	start_mlx(t_game *game);

void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_down(t_game *game);

int		hook_idle(void *ptr);
int		hook_close(t_game *game);
int		hook_key(int key, t_game *game);

void	ft_panic(t_game *game, char *error);
void	ft_exit(t_game *game, int status);
void	ft_free_game(t_game *game);
void	ft_win(t_game *game);

#endif
