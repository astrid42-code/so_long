/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:32:44 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/14 12:00:16 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    ft_draw_map(t_param *param/*, int wall, int floor, int exit, int collectible, int player*/) // appeler macros pour couleurs
{
    int i;
    int j;
    t_square *square;

    i = 0;
    while (param->map[i++])
    {
        j = 0;
        while (param->map[i][j++])
        {
            if (param->map[i][j] == '1')
            {
                ft_init_size_square(square, i, j);
                ft_draw_square(param, square, RED);
            }
        }
    }
}

void    ft_draw_square(t_param *param, t_square *square, int wall)
{
    int i;
    int j;

    i = 0;
    while (i < square->size)
    {
        j = 0;
        while (j < square->size)
        {
            my_mlx_pixel_put(param->mlx, square->x +j, square->y + i, wall);
            j++;
        }
        i++;
    }
    
}

void    ft_init_size_square(t_square *square, int i, int j)
{
    *square = (t_square){j * SIZE + SIZE, i * SIZE + SIZE, SIZE};
}