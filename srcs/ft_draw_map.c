/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:32:44 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/07/05 12:22:50 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	ft_draw_wall(t_square *square, t_solong *solong)
{
	int tmp_x;
	int tmp_y;
	char *texture;
	
	tmp_x = SIZE;
	texture = "wall.xpm";
	ft_get_texture(solong, 1, texture);
	while (tmp_x != 0)
	{
		tmp_y = SIZE;
		while (tmp_y != 0)
		{
			ft_get_pixel(solong, tmp_x, tmp_y);
			//mlx_put_image_to_window(solong->img->mlx, solong->img->win, solong->param->wall->img, square->x, square->y);
			tmp_y--;
		}
		tmp_x--;
	    //printf("x = %d\n", tmp_x);
	}
}

void	ft_draw_floor(t_square *square, t_solong *solong)
{
	int tmp_x;
	int tmp_y;
	int color;
	char *texture;
	
	tmp_x = SIZE;
	texture = "floor.xpm";
	ft_get_texture(solong, 2, texture);
	while (tmp_x != 0)
	{
		tmp_y = SIZE;
		while (tmp_y != 0)
		{
			color = ft_get_pixel(solong, tmp_x, tmp_y, 2);
			my_mlx_pixel_put(solong->img, square->x + tmp_x, square->y + tmp_y, color);
			//mlx_put_image_to_window(solong->img->mlx, solong->img->win, solong->param->floor->img, square->x, square->y);
			tmp_y--;
		}
		tmp_x--;
	}
}

void    ft_draw_player(t_square *square, t_solong *solong)
{
	int tmp_x;
	int tmp_y;
	char *texture;
	
	tmp_x = SIZE;
	texture = "pingu1.xpm";
	ft_get_texture(solong, 3, texture);
	while (tmp_x != 0)
	{
		tmp_y = SIZE;
		while (tmp_y != 0)
		{
			ft_get_pixel(solong, tmp_x, tmp_y);
			//my_mlx_pixel_put(solong->img, square->x + tmp_x, square->y + tmp_y, solong->param->player->addr);
			//puts("che");
			//printf("square x = %d square y = %d\n", square->x, square->y);
			//my_mlx_put_pixel_to_img(solong, solong->param->player, square->x + tmp_x, square->y + tmp_y);
			//mlx_put_image_to_window(solong->img->mlx, solong->img->win, solong->param->player->img, square->x, square->y);
			tmp_y--;
		}
		tmp_x--;
	} 
}

void    ft_draw_exit(t_square *square, t_solong *solong)
{
	int tmp_x;
	int tmp_y;
	char *texture;
	
	tmp_x = SIZE;
	texture = "exit.xpm";
	ft_get_texture(solong, 4, texture);
	while (tmp_x != 0)
	{
		tmp_y = SIZE;
		while (tmp_y != 0)
		{
			ft_get_pixel(solong, tmp_x, tmp_y);
			//mlx_put_image_to_window(solong->img->mlx, solong->img->win, solong->param->exit->img, square->x, square->y);
			tmp_y--;
		}
		tmp_x--;
	}
}

void    ft_draw_coll(t_square *square, t_solong *solong)
{
	int tmp_x;
	int tmp_y;
	char *texture;
	
	tmp_x = SIZE;
	texture = "fish.xpm";
	ft_get_texture(solong, 5, texture);
	while (tmp_x != 0)
	{
		tmp_y = SIZE;
		while (tmp_y != 0)
		{
			ft_get_pixel(solong, tmp_x, tmp_y);
			//mlx_put_image_to_window(solong->img->mlx, solong->img->win, solong->param->collectible->img, square->x, square->y);
			tmp_y--;
		}
		tmp_x--;
	}
}
