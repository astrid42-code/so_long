/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:39:25 by astridgault       #+#    #+#             */
/*   Updated: 2021/07/30 14:51:57 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_basic_error(int argc)
{
	write(1, "Error\n", 6);
	if (argc < 2)
		write(1, "There is no mapfile\n", 20);
	else if (argc > 2)
		write(1, "Wrong number of arguments\n", 26);
	else if (argc == 2)
		write(1, "This mapfile is not valid\n", 26);
}

void	ft_error_map(int error)
{
	write(1, "Error\n", 6);
	if (error == 1)
		write(1, "Invalid map!\n", 13);
	else if (error == 2)
		write(1, "There is more than one player\n", 30);
	else if (error == 3)
		write(1, "There is no player\n", 19);
	else if (error == 4)
		write(1, "There is no collectible\n", 24);
	else if (error == 5)
		write(1, "There is no exit\n", 17);
}

void	ft_error_mlx(int error)
{
	write(1, "Error\n", 6);
	if (error == 1)
		write(1, "A texture is missing!\n", 22);
}

void	ft_error_dir(t_param *param)
{
	write(1, "Error\n", 6);
	write(1, "There is no mapfile\n", 20);
	free(param->file);
	exit(1);
}
