/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:48:23 by ehafiane          #+#    #+#             */
/*   Updated: 2024/02/18 14:24:11 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "mlx.h"

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
	int		player_x;
	int		player_y;
	int		collect_cnt;
	int		player_mv;
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
void	update_map(t_all *slg);
size_t	ft_strlen(const char *str);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif