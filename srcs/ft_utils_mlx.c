/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:58:53 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/07/30 13:10:43 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keypress(int key, t_sl *sl)
{
	int	i;
	int	j;

	i = sl->param->pos_x;
	j = sl->param->pos_y;
	if (key == 119)
		ft_actions(sl, sl->param->pos_x - 1, j);
	else if (key == 115)
		ft_actions(sl, sl->param->pos_x + 1, j);
	else if (key == 97)
		ft_actions(sl, i, sl->param->pos_y - 1);
	else if (key == 100)
		ft_actions(sl, i, sl->param->pos_y + 1);
	else if (key == 65307)
		ft_close(sl);
	return (1);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_pp / 8));
	*(unsigned int *)dst = color;
}

int	*ft_get_pixel(t_sl *sl, int x, int y, int test)
{
	if (test == 1)
		return ((int *)(sl->param->wall.addr
			+ (y * sl->param->wall.line_length
				+ (x * sl->param->wall.bpp / 8))));
	if (test == 2)
		return ((int *)(sl->param->floor.addr
			+ (y * sl->param->floor.line_length
				+ (x * sl->param->floor.bpp / 8))));
	if (test == 3)
		return ((int *)(sl->param->player.addr
			+ (y * sl->param->player.line_length
				+ (x * sl->param->player.bpp / 8))));
	if (test == 4)
		return ((int *)(sl->param->exit.addr
			+ (y * sl->param->exit.line_length
				+ (x * sl->param->exit.bpp / 8))));
	if (test == 5)
		return ((int *)(sl->param->coll.addr
			+ (y * sl->param->coll.line_length
				+ (x * sl->param->coll.bpp / 8))));
	return (0);
}	

void	ft_draw(t_sl *sl, int i, int j)
{
	if (sl->param->map[i][j] == '1')
		ft_draw_wall(&sl->square, sl);
	else if (sl->param->pos_x == i && sl->param->pos_y == j)
		ft_draw_player(&sl->square, sl);
	else if (sl->param->map[i][j] == 'C')
		ft_draw_coll(&sl->square, sl);
	else if (sl->param->map[i][j] == 'E')
		ft_draw_exit(&sl->square, sl);
	else
		ft_draw_floor(&sl->square, sl);
}
