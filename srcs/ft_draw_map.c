/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:32:44 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/07/01 15:50:11 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	ft_draw_wall(t_square *square, t_solong *solong)
{
	int tmp_x;
	int tmp_y;

	tmp_x = SIZE;
	while (tmp_x != 0)
	{
		tmp_y = SIZE;
		while (tmp_y != 0)
		{
			my_mlx_pixel_put(solong->img, square->x + tmp_x, square->y + tmp_y, RED);
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
	
	tmp_x = SIZE;
	while (tmp_x != 0)
	{
		tmp_y = SIZE;
		while (tmp_y != 0)
		{
			my_mlx_pixel_put(solong->img, square->x + tmp_x, square->y + tmp_y, GREEN);
			tmp_y--;
		}
		tmp_x--;
	}
}

void    ft_draw_player(t_square *square, t_solong *solong)
{
	int tmp_x;
	int tmp_y;
	
	tmp_x = SIZE;
	while (tmp_x != 0)
	{
		tmp_y = SIZE;
		while (tmp_y != 0)
		{
			my_mlx_pixel_put(solong->img, square->x + tmp_x, square->y + tmp_y, BLUE);
			tmp_y--;
		}
		tmp_x--;
	}
}

void    ft_draw_exit(t_square *square, t_solong *solong)
{
	int tmp_x;
	int tmp_y;
	
	tmp_x = SIZE;
	while (tmp_x != 0)
	{
		tmp_y = SIZE;
		while (tmp_y != 0)
		{
			my_mlx_pixel_put(solong->img, square->x + tmp_x, square->y + tmp_y, YELLOW);
			tmp_y--;
		}
		tmp_x--;
	}
}

void    ft_draw_coll(t_square *square, t_solong *solong)
{
	int tmp_x;
	int tmp_y;
	
	tmp_x = SIZE;
	while (tmp_x != 0)
	{
		tmp_y = SIZE;
		while (tmp_y != 0)
		{
			my_mlx_pixel_put(solong->img, square->x + tmp_x, square->y + tmp_y, ORANGE);
			tmp_y--;
		}
		tmp_x--;
	}
}
/*
void	ft_get_texture(t_solong *solong)
{
	t_texture texture;

	// checker le .xpm > valide ou non (si non : exit)
	if 
	
	// transformer le .xpm avec mlx_xpm_to_image(solong, xxx.xpm, SIZE, SIZE);
	// mlx_get_data_adress(solong->img->img, &solong->img.bits_pp, &solong->img.line_length, &solong->img.endian);
	// associer chaque texture a son char * dans la struct
	// solong->texture = &texture;
	// fct verif struct : si l'un des elements de la struct est nul : erreur
}*/