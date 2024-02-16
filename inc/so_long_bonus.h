/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:22:33 by ehafiane          #+#    #+#             */
/*   Updated: 2024/02/16 23:13:56 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../libft/libft.h"
# include "get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "mlx.h"
# include <stdio.h>

typedef struct s_all
{
	char	**mapi;
	void	*mlx_ptr;
	void	*mlx_win;
	void	*collect_image;
	void	*opexit_image;
	void	*closed_exit_image;
	void	*floor_image;
	void	*player_image;
	void	*wall_image;
	void	*enemy_image;
	int		player_x;
	int		player_y;
	int		collect_cnt;
	int		enemy_cnt;
	int		player_mv;
	int		**enemy_tab;	
}	t_all;

char	**map_parcing(char *map_filer);
void	so_long(t_all *slg, char *map_filer);
int		player_moves(int key, t_all *slg);
void	check_all_map(char **mapi);
void	valid_acces(char **mapi);
void	ft_error(char *error_msg, int ext_n, char **free_this);
void	ft_free(char **free_this);
void	exit_free(t_all *sol);
int		set_windows_officiel(t_all *slg);
void	*create_image(void	*mlx_ptr, char *image);
int		enemy_counter(t_all *slg);
int		update_enemy(t_all *slg);
void	update_map(t_all *slg);
int		exit_finish(t_all *slg);
void	enemy_pos_tab(t_all *slg);
void	help(int j, int i, int e, t_all *slg);

#endif