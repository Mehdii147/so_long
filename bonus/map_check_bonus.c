/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:38:52 by ehafiane          #+#    #+#             */
/*   Updated: 2024/02/10 18:42:44 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	check_lines_lenth(char **mapi)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(*mapi);
	while (mapi[i])
	{
		if ((int)ft_strlen(mapi[i]) != len || len < 3)
			ft_error("\033[1;31m invalid line len \033[0m", 1, mapi);
		i++;
	}
	if (i < 3)
		ft_error("\033[1;31m invalid lines (> 3) \033[0m", 1, mapi);
}

void	check_walls(char **mapi)
{
	int	i;
	int	j;

	i = -1;
	while (mapi[0][++i])
		if (mapi[0][i] != '1')
			ft_error("\033[1;31m not surrounded by walls \033[0m", 1, mapi);
	i = 0;
	while (mapi[++i])
	{
		if (mapi[i][0] != '1')
			ft_error("\033[1;31m not surrounded by walls \033[0m", 1, mapi);
		j = 0;
		while (mapi[i][j + 1])
			j++;
		if (mapi[i][j] != '1')
			ft_error("\033[1;31m not surrounded by walls \033[0m", 1, mapi);
	}
	j = -1;
	i--;
	while (mapi[i][++j])
		if (mapi[i][j] != '1')
			ft_error("\033[1;31m not surrounded by walls \033[0m", 1, mapi);
}

void	check_characters(char **mapi)
{
	int	i;
	int	j;

	i = 0;
	while (mapi[i])
	{
		j = 0;
		while (mapi[i][j])
		{
			if (mapi[i][j] != '0' && mapi[i][j] != '1' && mapi[i][j] != 'C' &&
				mapi[i][j] != 'E' && mapi[i][j] != 'P' && mapi[i][j] != 'S')
				ft_error("\033[1;31m invalid characters \033[0m", 1, mapi);
			j++;
		}
		i++;
	}
}

void	check_characters_nb(char **mapi)
{
	int	p;
	int	e;
	int	c;
	int	j;
	int	i;

	p = 0;
	e = 0;
	c = 0;
	j = -1;
	while (mapi[++j])
	{
		i = -1;
		while (mapi[j][++i])
		{
			if (mapi[j][i] == 'C')
				c++;
			else if (mapi[j][i] == 'E')
				e++;
			else if (mapi[j][i] == 'P')
				p++;
		}
	}
	if (c < 1 || e != 1 || p != 1)
		ft_error("\033[1;31m invalid characters \033[0m", 1, mapi);
}

void	check_all_map(char **mapi)
{
	check_lines_lenth(mapi);
	check_walls(mapi);
	check_characters(mapi);
	check_characters_nb(mapi);
	valid_acces(mapi);
}
