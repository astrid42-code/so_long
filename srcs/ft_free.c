/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:59:09 by astridgault       #+#    #+#             */
/*   Updated: 2021/07/30 13:30:19 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_param *param)
{
	int	i;

	i = 0;
	while (param->map[i])
	{
		free(param->map[i]);
		param->map[i] = NULL;
		i++;
	}
	free(param->map);
}

void	ft_free(t_param *param)
{
	free(param->file);
	if (!param->map)
		return ;
	ft_free_map(param);
	param->file = NULL;
}

int	ft_close(t_sl *sl)
{
	if (sl->img.img)
		mlx_destroy_image(sl->img.mlx, sl->img.img);
	if (sl->img.win)
		mlx_destroy_window(sl->img.mlx, sl->img.win);
	if (sl->img.mlx)
		mlx_destroy_display(sl->img.mlx);
	free(sl->img.mlx);
	ft_free(sl->param);
	exit (0);
	return (0);
}
