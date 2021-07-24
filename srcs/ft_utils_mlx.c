/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:58:53 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/07/24 17:24:39 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keypress(int key, t_solong *solong)
{
	int i;
	int j;
	
	i = solong->param->pos_x;
	j = solong->param->pos_y;
	//printf("key = %d\n", key);
	if (key == 119) // w
	{	
		i = solong->param->pos_x - 1;
		ft_actions(solong, i, j);
	}
	else if (key == 115) // s
	{
		i = solong->param->pos_x + 1;
		ft_actions(solong, i, j);
	}
	else if (key == 97) // a
	{
		j = solong->param->pos_y - 1;
		ft_actions(solong, i, j);
	}	
	else if (key == 100) // d
	{
		j = solong->param->pos_y + 1;
		ft_actions(solong, i, j);
	}
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

void	my_mlx_put_pixel_to_img(t_solong *solong, t_text *player, int x, int y)
{
	int tmp_x;
	int tmp_y;
	(void)x;
	(void)y;

	tmp_x = SIZE;
	while (tmp_x != 0)
	{
		tmp_y = SIZE;
		while (tmp_y != 0)
		{
			my_mlx_pixel_put(player->img, solong->square->x + tmp_x, solong->square->y + tmp_y, (int)solong->param->player->img);
			tmp_y--;
			printf("x = %d y = %d\n", tmp_x, tmp_y);
		}
		tmp_x--;
	}
}

int	*ft_get_pixel(t_solong *solong, int x, int y, int test)
{
	if (test == 2)
	{
		printf("img-linelength = %d\n", solong->param->floor->line_length);
		return ((int*)(solong->img->addr + (y * solong->img->line_length + (x * solong->img->bits_pp / 8))));
	}
	return (0);
}	

/*
void	ft_win(t_solong *solong)
{
	int tmp_x;
	int tmp_y;
	
	
	tmp_x = 42 * solong->param->size_x;
	while (tmp_x != 0)
	{
		tmp_y = 42 * solong->param->size_y;
		while (tmp_y != 0)
		{
			my_mlx_pixel_put(solong->img, tmp_x, tmp_y, BLACK);
		printf("x = %d = %d\n", tmp_x, tmp_y);
			tmp_y--;			
		}
		tmp_x--;
	}
}

{
	int tmp_x;
	int tmp_y;
	
	utiliser ft_bzero ou mlx_clear_window pour mettre img noire

	
	//solong->img->img = mlx_new_image(solong->img->mlx, 0, 0);
	//solong->img->addr = mlx_get_data_addr(solong->img->img, &solong->img->bits_pp, &solong->img->line_length, &solong->img->endian);
	tmp_x = 42 * solong->param->size_y;
	printf("x = %d\n", tmp_x);
	while (tmp_x != 0)
	{
		tmp_y = 42 * solong->param->size_y;
		printf("y = %d\n", tmp_y);
		while (tmp_y != 0)
		{
			my_mlx_pixel_put(solong->img, tmp_x, tmp_y, BLACK);
			tmp_y--;
		}
		tmp_x--;
	}
	
	int size;
	size = solong->param->size_x * solong->param->size_y * SIZE;
	printf("s = %d\n", size);
	ft_memset(solong->img->img, 0, size);
}*/
