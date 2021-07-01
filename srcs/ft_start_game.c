/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:59:03 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/07/01 17:45:06 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_start_game(t_solong *solong)
{
	t_img	img;
	t_square square;
	int x;
	int y;
	
	x = 42 * solong->param->size_y;
	y = 42 * solong->param->size_x;
	//ft_get_texture(solong);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, x, y, "Pingu's game");
	img.img = mlx_new_image(img.mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_pp, &img.line_length, &img.endian);
	solong->img = &img;
	solong->square = &square;
	mlx_hook(img.win, 2, 1L<<0, ft_keypress, solong);
	mlx_hook(img.win, 17, 1L<<17, ft_close, solong);
	mlx_loop_hook(img.mlx, ft_minimap, solong);
	mlx_loop(img.mlx);
	return (1);
}

/*
apres avoir mis les textures et tout j'appellerai dans la fct finale le put_image_to_window
> lance une fct 
*/

int	ft_minimap(t_solong *solong)
{
	int 		i;
	int 		j;

	i = 0;
	j = 0;
	ft_init_size_square(solong->square, i, j);
//	if (solong->param->win == 1)
//		ft_win(solong);
//	else
	{
		while (solong->param->map[i])
		{
			j = 0;
			while (solong->param->map[i][j])
			{
				ft_init_size_square(solong->square, i, j);
				if (solong->param->map[i][j] == '1')
					ft_draw_wall(solong->square, solong);
				else if (solong->param->pos_x == i && solong->param->pos_y == j)
					ft_draw_player(solong->square, solong);
				else if (solong->param->map[i][j] == 'C')
					ft_draw_coll(solong->square, solong);
				else if (solong->param->map[i][j] == 'E')
					ft_draw_exit(solong->square, solong);
				else
					ft_draw_floor(solong->square, solong);
				j++;
			}
			i++;
		}
	}
	mlx_put_image_to_window(solong->img->mlx, solong->img->win, solong->img->img, 0, 0);
	return (0);
}

void    ft_init_size_square(t_square *square, int i, int j)
{
    *square = (t_square){j * SIZE , i * SIZE , SIZE};
}

