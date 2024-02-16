/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:36:45 by ehafiane          #+#    #+#             */
/*   Updated: 2024/02/16 22:50:32 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	move_up(t_all *slg)
{
	int	prec_y;

	prec_y = slg->player_y;
	if (slg->mapi[slg->player_y - 1][slg->player_x] == '0')
		slg->player_y -= 1;
	else if (slg->mapi[slg->player_y - 1][slg->player_x] == 'E')
	{
		if (slg->collect_cnt == 0)
			(ft_putstr_fd("YOU WON", 1), exit_free(slg));
		else
			slg->player_y -= 1;
	}
	else if (slg->mapi[slg->player_y - 1][slg->player_x] == 'S')
		(ft_putstr_fd("\033[1;31m GAME OVER \033[0m", 1), exit_free(slg));
	else if (slg->mapi[slg->player_y - 1][slg->player_x] == 'C')
	{
		slg->mapi[--(slg->player_y)][slg->player_x] = '0';
		slg->collect_cnt--;
	}
	if (prec_y != slg->player_y)
		slg->player_mv++;
	slg->player_image = create_image(slg->mlx_ptr,
			"./textures/player_back.xpm");
}

void	move_down(t_all *slg)
{
	int	prec_y;

	prec_y = slg->player_y;
	if (slg->mapi[slg->player_y + 1][slg->player_x] == '0')
		slg->player_y += 1;
	else if (slg->mapi[slg->player_y + 1][slg->player_x] == 'E')
	{
		if (slg->collect_cnt == 0)
			(ft_putstr_fd("YOU WON", 1), exit_free(slg));
		else
			slg->player_y += 1;
	}
	else if (slg->mapi[slg->player_y + 1][slg->player_x] == 'S')
		(ft_putstr_fd("\033[1;31m GAME OVER \033[0m", 1), exit_free(slg));
	else if (slg->mapi[slg->player_y + 1][slg->player_x] == 'C')
	{
		slg->mapi[++(slg->player_y)][slg->player_x] = '0';
		slg->collect_cnt--;
	}
	if (prec_y != slg->player_y)
		slg->player_mv++;
	slg->player_image = create_image(slg->mlx_ptr, "./textures/player.xpm");
}

void	move_left(t_all *slg)
{
	int	prec_x;

	prec_x = slg->player_x;
	if (slg->mapi[slg->player_y][slg->player_x - 1] == '0')
		slg->player_x -= 1;
	else if (slg->mapi[slg->player_y][slg->player_x - 1] == 'E')
	{
		if (slg->collect_cnt == 0)
			(ft_putstr_fd("YOU WON", 1), exit_free(slg));
		else
			slg->player_x -= 1;
	}
	else if (slg->mapi[slg->player_y][slg->player_x - 1] == 'S')
		(ft_putstr_fd("\033[1;31m GAME OVER \033[0m", 1), exit_free(slg));
	else if (slg->mapi[slg->player_y][slg->player_x - 1] == 'C')
	{
		slg->mapi[slg->player_y][--(slg->player_x)] = '0';
		slg->collect_cnt--;
	}
	if (prec_x != slg->player_x)
		slg->player_mv++;
	slg->player_image = create_image(slg->mlx_ptr,
			"./textures/player_left.xpm");
}

void	move_right(t_all *slg)
{
	int	prec_x;

	prec_x = slg->player_x;
	if (slg->mapi[slg->player_y][slg->player_x + 1] == '0')
		slg->player_x += 1;
	else if (slg->mapi[slg->player_y][slg->player_x + 1] == 'E')
	{
		if (slg->collect_cnt == 0)
			(ft_putstr_fd("YOU WON", 1), exit_free(slg));
		else
			slg->player_x += 1;
	}
	else if (slg->mapi[slg->player_y][slg->player_x + 1] == 'S')
		(ft_putstr_fd("\033[1;31m GAME OVER \033[0m", 1), exit_free(slg));
	else if (slg->mapi[slg->player_y][slg->player_x + 1] == 'C')
	{
		slg->mapi[slg->player_y][++(slg->player_x)] = '0';
		slg->collect_cnt--;
	}
	if (prec_x != slg->player_x)
		slg->player_mv++;
	slg->player_image = create_image(slg->mlx_ptr,
			"./textures/player_right.xpm");
}

int	player_moves(int key, t_all *slg)
{
	int	px;
	int	py;

	px = slg->player_x;
	py = slg->player_y;
	if (key == 13 || key == 126)
		move_up(slg);
	if (key == 1 || key == 125)
		move_down(slg);
	if (key == 0 || key == 123)
		move_left(slg);
	if (key == 2 || key == 124)
		move_right(slg);
	if (key == 53)
		exit_free(slg);
	update_map(slg);
	return (0);
}
