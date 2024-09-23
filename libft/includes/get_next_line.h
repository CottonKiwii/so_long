/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: CottonKiwii <julia.wolfram@gmx.at>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:22:40 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/23 15:20:26 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 24
# endif

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

/* get_next_line */
void	free_fb(char **buffer);
char	*get_next_line(int fd);
char	*ft_get_line(char *fbuff);
char	*ft_next_line(char *buffer, char *fbuff);

#endif
