/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:48:30 by astridgault       #+#    #+#             */
/*   Updated: 2021/06/08 22:25:51 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>
//# include <mlx.h>
//# include "../Libft/libft.h"
//# include "../mlx_linux/mlx.h"

# ifndef BUF_SIZE
#  define BUF_SIZE 42
# endif

typedef struct	s_param
{
	int i;
	int size;
	char *file;
	//char **map;
	int size_x; // taille ligne
	int size_y; // taille colonne
}				t_param;

// protos
int		main(int ac, char **av);
int		ft_read_data(int fd, t_param *param);
int		ft_stock_data(char	**data, t_param *param);
int		ft_check_data(char **data, int count, t_param *param);

// protos utils
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

// protos free
void	ft_free_map(t_param *param);

// protos gnl
int		get_next_line(int fd, char **line);
char	*ft_get_static(char *str, char buf[BUF_SIZE], int len);
char	*ft_stock_line(char *str, char **line);
char    **ft_get_file(int fd, int lvl);

// protos error
int		ft_checkbasic_error(int ac, char **av);
void	ft_basic_error(int ac);
void	ft_error_map(int error);

#endif