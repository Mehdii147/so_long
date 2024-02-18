/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:32:20 by ehafiane          #+#    #+#             */
/*   Updated: 2024/02/18 15:31:25 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long_bonus.h"

void	set_windows(t_all *slg, int x, int y)
{
	mlx_put_image_to_window(slg->mlx_ptr, slg->mlx_win,
		slg->floor_image, x * 60, y * 60);
	if (slg->mapi[y][x] == '1')
		mlx_put_image_to_window(slg->mlx_ptr, slg->mlx_win,
			slg->wall_image, x * 60, y * 60);
	else if (slg->mapi[y][x] == 'C')
		mlx_put_image_to_window(slg->mlx_ptr,
			slg->mlx_win, slg->collect_image, x * 60, y * 60);
	else if (slg->mapi[y][x] == 'E' && slg->collect_cnt > 0)
		mlx_put_image_to_window(slg->mlx_ptr,
			slg->mlx_win, slg->closed_exit_image, x * 60, y * 60);
	else if (slg->mapi[y][x] == 'E')
		mlx_put_image_to_window(slg->mlx_ptr,
			slg->mlx_win, slg->opexit_image, x * 60, y * 60);
	else if (slg->mapi[y][x] == 'S')
		mlx_put_image_to_window(slg->mlx_ptr,
			slg->mlx_win, slg->enemy_image, x * 60, y * 60);
	mlx_put_image_to_window(slg->mlx_ptr, slg->mlx_win,
		slg->player_image, slg->player_x * 60, slg->player_y * 60);
}

int	set_windows_officiel(t_all *slg)
{
	int	x;
	int	y;

	y = 0;
	while (slg->mapi[y])
	{
		x = 0;
		while (slg->mapi[y][x])
		{
			set_windows(slg, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	exit_finish(t_all *slg)
{
	ft_putstr_fd("\033[1;31m=GAME OVER=\n", 1);
	exit_free(slg);
	return (0);
}

void	update_map(t_all *slg)
{
	char	*str;

	str = ft_itoa(slg->player_mv);
	mlx_clear_window(slg->mlx_ptr, slg->mlx_win);
	set_windows_officiel(slg);
	mlx_string_put(slg->mlx_ptr, slg->mlx_win, 15, 15, 0xFFFFFF, "MOVES: ");
	mlx_string_put(slg->mlx_ptr, slg->mlx_win, 80, 15, 0xFFFFFF, str);
	free(str);
}

int	main(int ac, char **av)
{
	t_all	slg;

	if (ac != 2)
		ft_error("\033[1;31m invalid argument number \033[0m", 1, NULL);
	if (ft_strncmp(ft_strrchr(av[1], '.'), ".ber"))
		ft_error("\033[1;31m not ber extension!\033[0m", 1, NULL);
	so_long(&slg, av[1]);
	set_windows_officiel(&slg);
	mlx_hook(slg.mlx_win, 2, 0, player_moves, &slg);
	mlx_hook(slg.mlx_win, 17, 0, exit_finish, &slg);
	mlx_loop_hook(slg.mlx_ptr, &update_enemy, &slg);
	mlx_loop(slg.mlx_ptr);
}
