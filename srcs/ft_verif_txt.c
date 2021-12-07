/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_txt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 15:59:55 by asgaulti          #+#    #+#             */
/*   Updated: 2021/07/30 15:23:12 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_verif_wall(t_sl *sl, char *texture)
{
	if (ft_strncmp(texture, "wall.xpm", 8) == 0)
	{
		sl->param->wall.img = mlx_xpm_file_to_image(sl->img.mlx,
				"textures/wall.xpm", &sl->param->wall.width,
				&sl->param->wall.height);
		if (sl->param->wall.img == NULL)
		{
			ft_error_mlx(1);
			ft_close(sl);
		}
		sl->param->wall.addr = mlx_get_data_addr
			(sl->param->wall.img, &sl->param->wall.bpp,
				&sl->param->wall.line_length, &sl->param->wall.endian);
	}
	else
	{
		ft_error_mlx(1);
		ft_close(sl);
	}
}

void	ft_verif_floor(t_sl *sl, char *texture)
{
	if (ft_strncmp(texture, "floor.xpm", 9) == 0)
	{
		sl->param->floor.img = mlx_xpm_file_to_image(sl->img.mlx,
				"textures/floor.xpm", &sl->param->floor.width,
				&sl->param->floor.height);
		if (sl->param->floor.img == NULL)
			ft_close(sl);
		sl->param->floor.addr = mlx_get_data_addr
			(sl->param->floor.img, &sl->param->floor.bpp,
				&sl->param->floor.line_length, &sl->param->floor.endian);
	}
	else
	{
		ft_error_mlx(1);
		ft_close(sl);
	}
}

void	ft_verif_player(t_sl *sl, char *texture)
{
	if (ft_strncmp(texture, "pingu.xpm", 9) == 0)
	{
		sl->param->player.img = mlx_xpm_file_to_image(sl->img.mlx,
				"textures/pingu.xpm", &sl->param->player.width,
				&sl->param->player.height);
		if (sl->param->player.img == NULL)
			ft_close(sl);
		sl->param->player.addr = mlx_get_data_addr
			(sl->param->player.img, &sl->param->player.bpp,
				&sl->param->player.line_length, &sl->param->player.endian);
	}
	else
	{
		ft_error_mlx(1);
		ft_close(sl);
	}
}

void	ft_verif_exit(t_sl *sl, char *texture)
{
	if (ft_strncmp(texture, "bh.xpm", 6) == 0)
	{
		sl->param->exit.img = mlx_xpm_file_to_image(sl->img.mlx,
				"textures/bh.xpm", &sl->param->exit.width,
				&sl->param->exit.height);
		if (sl->param->exit.img == NULL)
			ft_close(sl);
		sl->param->exit.addr = mlx_get_data_addr
			(sl->param->exit.img, &sl->param->exit.bpp,
				&sl->param->exit.line_length, &sl->param->exit.endian);
	}
	else
	{
		ft_error_mlx(1);
		ft_close(sl);
	}
}

void	ft_verif_coll(t_sl *sl, char *texture)
{
	if (ft_strncmp(texture, "coll.xpm", 8) == 0)
	{
		sl->param->coll.img = mlx_xpm_file_to_image(sl->img.mlx,
				"textures/coll.xpm", &sl->param->coll.width,
				&sl->param->coll.height);
		if (sl->param->coll.img == NULL)
			ft_close(sl);
		sl->param->coll.addr = mlx_get_data_addr
			(sl->param->coll.img, &sl->param->coll.bpp,
				&sl->param->coll.line_length, &sl->param->coll.endian);
	}
	else
	{
		ft_error_mlx(1);
		ft_close(sl);
	}
}
