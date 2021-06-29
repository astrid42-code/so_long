/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:58:53 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/29 19:49:41 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keypress(int key, t_solong *solong)
{
	//printf("key = %d\n", key);
	if (key == 119) // w
		ft_up(solong);
	else if (key == 97) // a
		ft_left(solong);
	else if (key == 115) // s
		ft_down(solong);
	else if (key == 100) // d
		ft_right(solong);
	else if (key == 65307) // esc
	{
		ft_close(solong);
	}
	return (1);
}

int	ft_close(t_solong *solong)
{
	//if (solong->param->win == 1)
	//	ft_win(solong);
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

void	ft_win(t_solong *solong)
{
	int tmp_x;
	int tmp_y;
	
	puts("che");
	tmp_x = SIZE;
	while (tmp_x != 0)
	{
		tmp_y = SIZE;
		while (tmp_y != 0)
		{
			my_mlx_pixel_put(solong->img, solong->square->x + tmp_x, solong->square->y + tmp_y, BLACK);
			tmp_y--;
		}
		tmp_x--;
	}
}