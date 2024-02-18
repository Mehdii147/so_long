/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:16:24 by ehafiane          #+#    #+#             */
/*   Updated: 2024/02/18 14:25:48 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*ptsrc;
	size_t			i;

	ptsrc = (unsigned char *)src;
	str = (unsigned char *)dst;
	i = 0;
	if (src == dst)
		return (0);
	while (i < n)
	{
		str[i] = ptsrc[i];
		i++;
	}
	return (dst);
}

static int	numb_alloc(int n)
{
	int	nb;

	nb = 0;
	if (n < 0)
	{
		nb++;
		n *= -1;
	}
	while (n != 0)
	{
		nb++;
		n = n / 10;
	}
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*old;
	int		len;
	int		tmp;

	len = numb_alloc(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	old = malloc(sizeof(char) * len + 1);
	if (!old)
		return (NULL);
	old[len] = '\0';
	if (n < 0)
	{
		old[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		tmp = n % 10 + 48;
		n /= 10;
		old[--len] = tmp;
	}
	return (old);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		len;

	len = ft_strlen(s1);
	cpy = malloc(len * sizeof(char) + 1);
	if (!cpy)
		return (NULL);
	ft_memcpy(cpy, s1, len);
	cpy[len] = '\0';
	return (cpy);
}
