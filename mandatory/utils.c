/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:42:46 by ehafiane          #+#    #+#             */
/*   Updated: 2024/02/10 17:08:08 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error(char *error_msg, int ext_n, char **free_this)
{
	ft_putstr_fd("error \n", 2);
	if (error_msg)
		ft_putendl_fd(error_msg, 2);
	else
		ft_putstr_fd(strerror(errno), 2);
	if (ext_n)
		exit(ext_n);
	if (free_this)
		ft_free(free_this);
}

void	ft_free(char **free_this)
{
	int	i;

	if (!free_this)
		return ;
	i = 0;
	while (free_this[i])
	{
		free(free_this[i]);
		i++;
	}
	free(free_this);
	free_this = NULL;
}

void	exit_free(t_all *slg)
{
	ft_free(slg->mapi);
	exit(0);
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*ret;
	int			len;

	len = ft_strlen(s);
	ret = (s + len);
	while (len >= 0)
	{
		if (*ret == (char)c)
			return ((char *)ret);
		ret--;
		len--;
	}
	if (!((char)c))
		return ((char *)s);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (1);
	while ((unsigned char)s1[i] && (unsigned char)s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
