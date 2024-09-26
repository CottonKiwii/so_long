/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolfram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:49:30 by jwolfram          #+#    #+#             */
/*   Updated: 2024/09/26 15:00:06 by jwolfram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarrdup(char **str)
{
	int		i;
	char	**cpy;

	if (!str)
		return (NULL);
	cpy = (char **)ft_calloc(ft_strarrlen(str) + 1, sizeof(char *));
	if (!cpy)
		return (NULL);
	i = 0;
	while (str[i])
	{
		cpy[i] = ft_strdup(str[i]);
		if (!cpy[i])
			return (ft_free_strarr(cpy), NULL);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
