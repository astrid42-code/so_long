/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:59:03 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/14 19:56:33 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_start_game(t_solong *solong)
{
	t_img	img;
	//t_vars	vars;
    
	//printf("r1 = %d\nr2 = %d\n", param->x, param->y);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 640, 480, "Pingu's game");
	img.img = mlx_new_image(img.mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_pp, &img.line_length, &img.endian);
	//my_mlx_pixel_put(&img, 50, 50, 0x00FF0000); // chger couleur + 5 et 5 (x et y) correspondent la position du pixel
	solong->img = &img;
	mlx_hook(img.win, 2, 1L<<0, ft_keypress, &img);
	mlx_hook(img.win, 17, 1L<<17, ft_close, &img);// 17 = DestroyNotify
	//mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);  // 0 0 pour le coin en haut a gche de ma window
	mlx_loop_hook(img.mlx, ft_minimap, solong);
	//mlx_loop_hook(vars.mlx, ft_minimap, param); //mlx_loop_hook(mlx, fct que je veux lancer a chaque frame, params de la fct) 
	//mlx_loop(vars.mlx);
	mlx_loop(img.mlx);
	return (1);
}

/*
apres avoir mis les textures et tout j'appellerai dans la fct finale le put_image_to_window
> lance une fct 

int	ft_minimap(t_param *param)
{
	ft_draw_map(param, 0xF7230C, 0x3A9D23, 0xFFFF00, 0xED7F10, 0x0000FF); // map, rouge (mur), vert (sol), jaune (exit), orange (collectible), bleu (joueur) > ENVOYER LES MACROS
	return (1);
}
*/

int	ft_minimap(t_solong *solong)
{
	int 		i;
	int 		j;
	t_square	square;

	i = 0;
	ft_init_size_square(&square, 0, 0);
	//printf("x = %d  y = %d\n", square.x, square.y);
	while (solong->param->map[i])
	{
		j = 0;
		while (solong->param->map[i][j])
		{
			//printf("c = %c i = %d  j = %d\n", solong->param->map[i][j], i, j);
			if (solong->param->map[i][j] == '1')
				ft_draw_wall(&square, solong, i, j);
			else if (solong->param->map[i][j] == '0')
				ft_draw_floor(&square, solong, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(solong->img->mlx, solong->img->win, solong->img->img, 0, 0);
	return (0);
}

void    ft_init_size_square(t_square *square, int i, int j)
{
    *square = (t_square){j * SIZE + SIZE, i * SIZE + SIZE, SIZE};
}

void	ft_draw_wall(t_square *square, t_solong *solong, int i, int j)
{
	int tmp_x;
	int tmp_y;
	(void)i;
	(void)j;
	
	tmp_x = square->x;
	while (tmp_x != 0)
	{
		tmp_y = square->y;
		while (tmp_y != 0)
		{
			my_mlx_pixel_put(solong->img, tmp_x, tmp_y, RED);
			tmp_y--;
		}
		tmp_x--;
	//printf("x = %d\n", tmp_x);
	}
}

void	ft_draw_floor(t_square *square, t_solong *solong, int i, int j)
{
	int tmp_x;
	int tmp_y;
	(void)i;
	(void)j;
	
	tmp_x = square->x;
	while (tmp_x != 0)
	{
		tmp_y = square->y;
		while (tmp_y != 0)
		{
			my_mlx_pixel_put(solong->img, tmp_x, tmp_y, GREEN);
			tmp_y--;
		}
		tmp_x--;
	}
}