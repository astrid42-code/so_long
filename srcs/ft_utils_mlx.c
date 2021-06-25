/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:58:53 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/25 16:02:06 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keypress(int key, t_solong *solong)
{
	//printf("key = %d\n", key);
	if (key == 119) // w
		ft_up(solong);
	else if (key == 97) // a
		ft_right(solong);
	else if (key == 115) // s
		ft_down(solong);
	else if (key == 100) // d
		ft_left(solong);
	else if (key == 65307) // esc
	{
		ft_close(solong);
	}
	return (1);
}

int	ft_close(t_solong *solong)
{
	mlx_destroy_image(solong->img->mlx, solong->img->img);
	mlx_destroy_window(solong->img->mlx, solong->img->win);
	mlx_destroy_display(solong->img->mlx);
	free(solong->img->mlx);
	ft_free(solong->param);
	exit (0);
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_pp / 8));
	*(unsigned int*)dst = color;
}