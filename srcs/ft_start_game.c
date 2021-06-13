/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:59:03 by asgaulti@st       #+#    #+#             */
/*   Updated: 2021/06/13 15:35:11 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_start_game(t_param *param)
{
	t_img	img;
	t_vars	vars;
	(void)param;
    
	//printf("r1 = %d\nr2 = %d\n", param->x, param->y);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Pingu's game");
	img.img = mlx_new_image(vars.mlx, 640, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_pp, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 50, 50, 0x00FF0000); // chger couleur + 5 et 5 (x et y) correspondent la position du pixel
	mlx_hook(vars.win, 2, 1L<<0, ft_keypress, &vars);
	mlx_hook(vars.win, 17, 1L<<17, ft_close, &vars); // 17 = DestroyNotify
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0); // a quoi correspondent les deux 0?
	mlx_loop(vars.mlx);
	return (1);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_pp / 8));
	*(unsigned int*)dst = color;
}
