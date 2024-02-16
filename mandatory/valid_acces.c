/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_acces.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:09:42 by ehafiane          #+#    #+#             */
/*   Updated: 2024/02/10 18:41:33 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**map_dup(char **mapi)
{
	char	**map_cpy;
	int		i;

	i = 0;
	while (mapi[i])
		i++;
	map_cpy = malloc((i + 1) * sizeof(char *));
	if (!map_cpy)
		ft_error(NULL, errno, mapi);
	i = 0;
	while (mapi[i])
	{
		map_cpy[i] = ft_strdup(mapi[i]);
		if (!map_cpy[i])
		{
			ft_free(map_cpy);
			ft_error(NULL, errno, mapi);
		}
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

void	change_map(char **map_cpy, int i, int j)
{
	map_cpy[i][j] = '1';
	if (map_cpy[i + 1][j] == '0' || map_cpy[i + 1][j] == 'C'
		|| map_cpy[i + 1][j] == 'E')
		change_map(map_cpy, i + 1, j);
	if (map_cpy[i - 1][j] == '0' || map_cpy[i - 1][j] == 'C'
		|| map_cpy[i - 1][j] == 'E')
		change_map(map_cpy, i - 1, j);
	if (map_cpy[i][j + 1] == '0' || map_cpy[i][j + 1] == 'C'
		|| map_cpy[i][j + 1] == 'E')
		change_map(map_cpy, i, j + 1);
	if (map_cpy[i][j - 1] == '0' || map_cpy[i][j - 1] == 'C'
		|| map_cpy[i][j - 1] == 'E')
		change_map(map_cpy, i, j - 1);
}

void	is_map_changed(char **map_cpy, char **mapi)
{
	int	i;
	int	j;

	i = 0;
	while (map_cpy[i])
	{
		j = 0;
		while (map_cpy[i][j])
		{
			if (map_cpy[i][j] == 'C' || map_cpy[i][j] == 'E')
			{
				ft_free(map_cpy);
				ft_error("\033[1;31m can't acces characters \033[0m", 1, mapi);
			}
			j++;
		}
		i++;
	}
}

void	valid_acces(char **mapi)
{
	char	**map_cpy;
	int		i;
	int		j;

	map_cpy = map_dup(mapi);
	i = 0;
	while (map_cpy[i])
	{
		j = 0;
		while (map_cpy[i][j])
		{
			if (map_cpy[i][j] == 'P')
				break ;
			j++;
		}
		if (map_cpy[i][j] == 'P')
			break ;
		i++;
	}
	change_map(map_cpy, i, j);
	is_map_changed(map_cpy, mapi);
	ft_free(map_cpy);
}
