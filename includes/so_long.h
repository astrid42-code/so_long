/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:48:30 by astridgault       #+#    #+#             */
/*   Updated: 2021/06/14 19:52:40 by asgaulti@st      ###   ########.fr       */
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
# include "../mlx_linux/mlx.h"

# ifndef BUF_SIZE
#  define BUF_SIZE 42
# endif

# define RED 0xF7230C
# define GREEN 0x3A9D23
# define YELLOW	0xFFFF00
# define ORANGE 0xED7F10
# define BLUE 0x0000FF

# define WIDTH 1980
# define HIGHT 1080
# define SIZE 10

typedef struct	s_square
{
	int x;
	int y;
	int size;
}				t_square;

typedef struct	s_img
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_pp; // bits per pixel
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_param
{
	int i;
	int size;
	int p;
	int c;
	int e;
	char *file;
	char **map;
	int size_x; // taille ligne
	int size_y; // taille colonne
}				t_param;

typedef struct	s_color
{
	int wall;
	int floor;
	int exit;
	int collectible;
	int player;
}				t_color;

typedef struct s_solong
{
	t_param	*param;
	t_img	*img;
}				t_solong;

// protos
int		main(int ac, char **av);
int		ft_read_data(int fd, t_param *param);
int		ft_stock_data(char	**data, t_param *param, int count);
int		ft_check_data(int count, t_param *param);
int		ft_check_charmap(int i, int j, t_param *param, int count);

// protos jeu
int		ft_start_game(t_solong *solong);
int		ft_minimap(t_solong *solong);
//void    ft_draw_map(t_param *param, int wall, int floor, int exit, int collectible, int player);
void    ft_draw_map(t_param *param);

// protos mlx
void    my_mlx_pixel_put(t_img *img, int x, int y, int color);
//int		close(int keycode, t_vars *vars);

// protos utils params
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_check_one(int i, int count, t_param *param);
int			ft_check_one_borders(int count, t_param *param);
int 		ft_check_rectangle(int count, t_param *param);
void		ft_count_c_e(int i, int j, t_param *param);
int			ft_check_letters(t_param *param);

// protos utils mlx
int			ft_keypress(int key, t_img *mlx);
int			ft_close(t_img *vars);
void	    ft_init_size_square(t_square *square, int i, int j);
void		ft_draw_wall(t_square *square, t_solong *solong, int i, int j);
void		ft_draw_floor(t_square *square, t_solong *solong, int i, int j);

// protos free
void		ft_free_map(t_param *param);
void		ft_free(t_param *param);

// protos gnl
int			get_next_line(int fd, char **line);
char		*ft_get_static(char *str, char buf[BUF_SIZE], int len);
char		*ft_stock_line(char *str, char **line);
char    	**ft_get_file(int fd, int lvl);

// protos error
int			ft_checkbasic_error(int ac, char **av);
void		ft_basic_error(int ac);
void		ft_error_map(int error);

#endif