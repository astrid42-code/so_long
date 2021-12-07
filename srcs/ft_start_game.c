/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:59:03 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/07/30 14:49:24 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_start_game(t_sl *sl)
{
	int	x;
	int	y;

	x = 42 * sl->param->size_y;
	y = 42 * sl->param->size_x;
	sl->img.mlx = mlx_init();
	if (!sl->img.mlx)
	{
		ft_close(sl);
		exit (1);
	}
	sl->img.win = mlx_new_window(sl->img.mlx, x, y, "Pingu's game");
	sl->img.img = mlx_new_image(sl->img.mlx, x, y);
	sl->img.addr = mlx_get_data_addr(sl->img.img, &sl->img.bits_pp,
			&sl->img.line_length, &sl->img.endian);
	ft_minimap(sl);
	mlx_hook(sl->img.win, 2, 1L << 0, ft_keypress, sl);
	mlx_hook(sl->img.win, 17, 1L << 17, ft_close, sl);
	mlx_loop_hook(sl->img.mlx, ft_minimap, sl);
	mlx_loop(sl->img.mlx);
	return (0);
}

int	ft_minimap(t_sl *sl)
{
	int		i;
	int		j;
	char	*count;

	i = 0;
	j = 0;
	ft_init_size_square(&sl->square, i, j);
	while (sl->param->map[i])
	{
		j = 0;
		while (sl->param->map[i][j])
		{
			ft_init_size_square(&sl->square, i, j);
			ft_draw(sl, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(sl->img.mlx,
		sl->img.win, sl->img.img, 0, 0);
	count = ft_itoa(sl->param->count);
	mlx_string_put(sl->img.mlx, sl->img.win, SIZE / 2, SIZE / 2,
		BLACK, count);
	free(count);
	return (0);
}

void	ft_init_size_square(t_square *square, int i, int j)
{
	*square = (t_square){j * SIZE, i * SIZE, SIZE};
}

t_text	ft_init_text(t_sl *sl)
{
	t_text	text;

	text = (t_text){0, 0, 0, sl->param->size_x, 0, SIZE, SIZE};
	return (text);
}

// doit on init text?? vu qu'on va init l img ensuite
void	ft_get_texture(t_sl *sl, int color, char *texture)
{
	if (color == 1)
	{
		sl->param->wall = ft_init_text(sl);
		ft_verif_wall(sl, texture);
	}
	if (color == 2)
	{
		sl->param->floor = ft_init_text(sl);
		ft_verif_floor(sl, texture);
	}
	if (color == 3)
	{
		sl->param->player = ft_init_text(sl);
		ft_verif_player(sl, texture);
	}
	if (color == 4)
	{
		sl->param->exit = ft_init_text(sl);
		ft_verif_exit(sl, texture);
	}
	if (color == 5)
	{
		sl->param->coll = ft_init_text(sl);
		ft_verif_coll(sl, texture);
	}
}
