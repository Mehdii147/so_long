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

#include "../inc/so_long_bonus.h"

void	ft_error(char *error_msg, int ext_n, char **free_this)
{
	ft_putstr_fd("error \n", 2);
	if (error_msg)
		ft_putendl_fd(error_msg, 2);
	else
		ft_putstr_fd(strerror(errno), 2);
	if (free_this)
		ft_free(free_this);
	if (ext_n)
		exit(ext_n);
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

void	help(int j, int i, int e, t_all *slg)
{
	slg->enemy_tab[e] = malloc(2 * sizeof(int));
	if (!slg->enemy_tab)
		(free(slg->enemy_tab), exit(1));
	slg->enemy_tab[e][0] = i;
	slg->enemy_tab[e][1] = j;
}
