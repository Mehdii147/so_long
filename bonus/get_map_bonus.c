/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:43:51 by ehafiane          #+#    #+#             */
/*   Updated: 2024/02/10 21:56:27 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	get_line_count(char *map_filer)
{
	int		cnt;
	int		fd;
	char	*line;

	cnt = 0;
	fd = open(map_filer, O_RDONLY);
	if (fd < 0)
		ft_error(NULL, errno, NULL);
	line = get_next_line(fd);
	while (line)
	{
		cnt++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (cnt);
}

char	**get_map(char *map_filer)
{
	char	**mapi;
	char	*line;
	int		fd;
	int		i;

	fd = open(map_filer, O_RDONLY);
	if (fd < 0)
		ft_error(NULL, errno, NULL);
	mapi = malloc((get_line_count(map_filer) + 1) * sizeof(char *));
	if (!mapi)
		ft_error(NULL, errno, NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = 0;
		mapi[i] = line;
		line = get_next_line(fd);
		i++;
	}
	mapi[i] = NULL;
	close(fd);
	return (mapi);
}

char	**map_parcing(char *map_filer)
{
	char	**mapi;

	mapi = get_map(map_filer);
	if (!mapi)
		ft_error("\033[1;31m empty map \033[0m", 1, NULL);
	check_all_map(mapi);
	return (mapi);
}
