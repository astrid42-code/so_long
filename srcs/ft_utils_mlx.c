/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:58:53 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/13 15:38:20 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_keypress(int key, t_vars *mlx)
{
	//printf("key = %d\n", key);
/*	if (key = 119) // w
		ft_up();
	else if (key == 97) // a
		ft_left();
	else if (key == 115) // s
		ft__right();
	else if (key == 100) // d
		ft_down();
	else*/ if (key == 65307) // esc
		ft_close(mlx);
	return (1);
}

int	ft_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	// free a faire? ft_free? frees malloc pour mlx?
	exit (0);
}