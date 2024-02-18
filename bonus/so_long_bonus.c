/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:45:18 by ehafiane          #+#    #+#             */
/*   Updated: 2024/02/18 12:47:39 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	*set_window(char **mapi, void *mlx_ptr)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	x = (int)ft_strlen(*mapi);
	while (mapi[i])
	{
		y++;
		i++;
	}
	return (mlx_new_window(mlx_ptr, x * 60, y * 60, "so_long_bonus by ACE"));
}

void	*create_image(void	*mlx_ptr, char *image)
{
	int		image_w;
	int		image_h;
	void	*image_ptr;

	image_ptr = mlx_xpm_file_to_image(mlx_ptr, image, &image_w, &image_h);
	return (image_ptr);
}

int	cnt_collect(t_all *slg)
{
	int	c;
	int	j;
	int	i;

	c = 0;
	i = 0;
	while (slg->mapi[i])
	{
		j = 0;
		while (slg->mapi[i][j])
		{
			if (slg->mapi[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

void	get_player_pos(t_all *slg)
{
	int	j;
	int	i;

	i = 0;
	while (slg->mapi[i])
	{
		j = 0;
		while (slg->mapi[i][j])
		{
			if (slg->mapi[i][j] == 'P')
			{
				slg->player_x = j;
				slg->player_y = i;
				slg->mapi[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	so_long(t_all *slg, char *map_filer)
{
	slg->mapi = map_parcing(map_filer);
	get_player_pos(slg);
	slg->player_mv = 0;
	slg->collect_cnt = cnt_collect(slg);
	slg->mlx_ptr = mlx_init();
	if (!slg->mlx_ptr)
		ft_error("mlx init fail", 1, slg->mapi);
	slg->mlx_win = set_window(slg->mapi, slg->mlx_ptr);
	if (!slg->mlx_win)
		ft_error("mlx window fail", 1, slg->mapi);
	slg->opexit_image = create_image(slg->mlx_ptr, "./textures/opexit.xpm");
	slg->closed_exit_image = create_image(slg->mlx_ptr, "./textures/nexit.xpm");
	slg->floor_image = create_image(slg->mlx_ptr, "./textures/floor.xpm");
	slg->wall_image = create_image(slg->mlx_ptr, "./textures/walls.xpm");
	slg->player_image = create_image(slg->mlx_ptr, "./textures/player.xpm");
	slg->collect_image = create_image(slg->mlx_ptr, "./textures/collect.xpm");
	slg->enemy_image = create_image(slg->mlx_ptr, "./textures/enemy.xpm");
	if (!slg->player_image || !slg->collect_image || !slg->floor_image
		|| !slg->wall_image || !slg->closed_exit_image || !slg->enemy_image)
		ft_error("\033[1;31m no image found \033[0m", 1, slg->mapi);
	enemy_pos_tab(slg);
}
