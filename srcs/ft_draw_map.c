/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:32:44 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/07/30 13:10:05 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_wall(t_square *square, t_sl *sl)
{
	int		tmp_x;
	int		tmp_y;
	int		*color;
	char	*texture;

	tmp_x = SIZE;
	texture = "wall.xpm";
	ft_get_texture(sl, 1, texture);
	while (tmp_x != 0)
	{
		tmp_y = SIZE;
		while (tmp_y != -1)
		{
			color = ft_get_pixel(sl, tmp_x, tmp_y, 1);
			my_mlx_pixel_put(&sl->img, square->x + tmp_x, square->y + tmp_y,
				*color);
			tmp_y--;
		}
		tmp_x--;
	}
	mlx_destroy_image(sl->img.mlx, sl->param->wall.img);
}

void	ft_draw_floor(t_square *square, t_sl *sl)
{
	int		tmp_x;
	int		tmp_y;
	int		*color;
	char	*texture;

	tmp_x = SIZE;
	texture = "floor.xpm";
	ft_get_texture(sl, 2, texture);
	while (tmp_x != 0)
	{
		tmp_y = SIZE;
		while (tmp_y != -1)
		{
			color = ft_get_pixel(sl, tmp_x, tmp_y, 2);
			my_mlx_pixel_put(&sl->img, square->x + tmp_x, square->y + tmp_y,
				*color);
			tmp_y--;
		}
		tmp_x--;
	}
	mlx_destroy_image(sl->img.mlx, sl->param->floor.img);
}

void	ft_draw_player(t_square *square, t_sl *sl)
{
	int		tmp_x;
	int		tmp_y;
	int		*color;
	char	*texture;

	tmp_x = SIZE;
	texture = "pingu.xpm";
	ft_get_texture(sl, 3, texture);
	while (tmp_x != 0)
	{
		tmp_y = SIZE;
		while (tmp_y != -1)
		{
			color = ft_get_pixel(sl, tmp_x, tmp_y, 3);
			my_mlx_pixel_put(&sl->img, square->x + tmp_x, square->y + tmp_y,
				*color);
			tmp_y--;
		}
		tmp_x--;
	}
	mlx_destroy_image(sl->img.mlx, sl->param->player.img);
}

void	ft_draw_exit(t_square *square, t_sl *sl)
{
	int		tmp_x;
	int		tmp_y;
	int		*color;
	char	*texture;

	tmp_x = SIZE;
	texture = "bh.xpm";
	ft_get_texture(sl, 4, texture);
	while (tmp_x != 0)
	{
		tmp_y = SIZE;
		while (tmp_y != -1)
		{
			color = ft_get_pixel(sl, tmp_x, tmp_y, 4);
			my_mlx_pixel_put(&sl->img, square->x + tmp_x, square->y + tmp_y,
				*color);
			tmp_y--;
		}
		tmp_x--;
	}
	mlx_destroy_image(sl->img.mlx, sl->param->exit.img);
}

void	ft_draw_coll(t_square *square, t_sl *sl)
{
	int		tmp_x;
	int		tmp_y;
	int		*color;
	char	*texture;

	tmp_x = SIZE;
	texture = "coll.xpm";
	ft_get_texture(sl, 5, texture);
	while (tmp_x != 0)
	{
		tmp_y = SIZE;
		while (tmp_y != -1)
		{
			color = ft_get_pixel(sl, tmp_x, tmp_y, 5);
			my_mlx_pixel_put(&sl->img, square->x + tmp_x, square->y + tmp_y,
				*color);
			tmp_y--;
		}
		tmp_x--;
	}
	mlx_destroy_image(sl->img.mlx, sl->param->coll.img);
}
