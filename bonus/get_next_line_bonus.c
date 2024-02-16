/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:22:10 by ehafiane          #+#    #+#             */
/*   Updated: 2024/02/10 16:22:12 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line_bonus.h"

char	*ft_read_stock(int fd, char *stock)
{
	char	*buff;
	int		readed;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	readed = 1;
	while (!ft_gnl_strchr(stock, '\n') && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buff);
			free(stock);
			return (NULL);
		}
		buff[readed] = '\0';
		stock = ft_gnl_strjoin(stock, buff);
	}
	free(buff);
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (0);
	stock[fd] = ft_read_stock(fd, stock[fd]);
	if (!stock[fd])
		return (NULL);
	line = ft_get_line(stock[fd]);
	stock[fd] = new_stock(stock[fd]);
	return (line);
}
