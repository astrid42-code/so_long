/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:48:30 by astridgault       #+#    #+#             */
/*   Updated: 2021/06/06 18:02:55 by astridgault      ###   ########.fr       */
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
	char *file;
}				t_param;

// protos
int		main(int ac, char **av);

// protos utils
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

// protos error
int		ft_checkbasic_error(int ac, char **av);
void	ft_basic_error(int ac);

#endif