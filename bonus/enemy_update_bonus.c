/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_update_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 00:12:33 by ehafiane          #+#    #+#             */
/*   Updated: 2024/02/17 23:25:03 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

int	enemy_counter(t_all *slg)
{
	int	j;
	int	i;
	int	e;

	i = 0;
	e = 0;
	while (slg->mapi[i])
	{
		j = 0;
		while (slg->mapi[i][j])
		{
			if (slg->mapi[i][j] == 'S')
				e++;
			j++;
		}
		i++;
	}
	return (e);
}

void	enemy_pos_tab(t_all *slg)
{
	int	e;
	int	j;
	int	i;

	e = 0;
	slg->enemy_cnt = enemy_counter(slg);
	slg->enemy_tab = malloc(slg->enemy_cnt * sizeof(int *));
	if (!slg->enemy_tab)
		(free(slg->enemy_tab), exit(1));
	i = -1;
	while (slg->mapi[++i])
	{
		j = -1;
		while (slg->mapi[i][++j])
		{
			if (slg->mapi[i][j] == 'S')
			{
				slg->enemy_tab[e] = malloc(2 * sizeof(int *));
				if (!slg->enemy_tab)
					(free(slg->enemy_tab), exit(1));
				slg->enemy_tab[e][0] = i;
				slg->enemy_tab[e++][1] = j;
			}
		}
	}
}

void	move_enemy_right(t_all *slg)
{
	int	i;
	int	*eny;

	i = 0;
	while (i < slg->enemy_cnt)
	{
		eny = slg->enemy_tab[i];
		if (slg->mapi[eny[0]][eny[1] + 1] == '1'
			|| slg->mapi[eny[0]][eny[1] + 1] == 'E'
			|| slg->mapi[eny[0]][eny[1] + 1] == 'C'
			|| slg->mapi[eny[0]][eny[1] + 1] == 'S')
			i++;
		else if (eny[1] + 1 == slg->player_x && eny[0] == slg->player_y)
			exit_finish(slg);
		else
		{
			slg->mapi[eny[0]][eny[1] + 1] = 'S';
			slg->mapi[eny[0]][eny[1]] = '0';
			eny[1]++;
			i++;
		}
	}
}

void	move_enemy_left(t_all *slg)
{
	int	i;
	int	*eny;

	i = 0;
	while (i < slg->enemy_cnt)
	{
		eny = slg->enemy_tab[i];
		if (slg->mapi[eny[0]][eny[1] - 1] == '1'
			|| slg->mapi[eny[0]][eny[1] - 1] == 'E'
			|| slg->mapi[eny[0]][eny[1] - 1] == 'C'
			|| slg->mapi[eny[0]][eny[1] - 1] == 'S')
			i++;
		else if (eny[1] - 1 == slg->player_x && eny[0] == slg->player_y)
			exit_finish(slg);
		else
		{
			slg->mapi[eny[0]][eny[1] - 1] = 'S';
			slg->mapi[eny[0]][eny[1]] = '0';
			eny[1]--;
			i++;
		}
	}
}

int	update_enemy(t_all *slg)
{
	static int	m;

	m++;
	if (m == 30)
		move_enemy_left(slg);
	else if (m == 60)
	{
		move_enemy_right(slg);
		m = 0;
	}
	update_map(slg);
	return (0);
}
