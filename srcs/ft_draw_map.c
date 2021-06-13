/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:32:44 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/13 17:46:03 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    ft_draw_map(t_param *param, int wall, int floor, int exit, int collectible, int player) // appeler macros pour couleurs
{
    int i;
    int j;

    i = 0;
    while (param->map[i])
    {
        j = 0;
        while (param->map[i][j++])
        {
            if (param->map[i][j] != '1')
                ft_draw_square
        }
    }
}