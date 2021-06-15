/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:32:44 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/15 17:16:00 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
void	ft_draw_wall(t_square *square, t_solong *solong, int i, int j)
{
	int tmp_x;
	int tmp_y;
	
	tmp_x = SIZE;
/*    if (i == 0 && j == 0)
    {
        square->x = 0;
        square->y = 0;
    }
    else
*/	{
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
