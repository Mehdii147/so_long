/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafiane <ehafiane@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:22:30 by ehafiane          #+#    #+#             */
/*   Updated: 2024/02/10 16:22:31 by ehafiane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_get_line(char *stock);
char	*new_stock(char *stock);
char	*ft_read_stock(int fd, char *stock);
char	*ft_gnl_strchr(char *s, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);
size_t	ft_gnl_strlen(char *s);

#endif
