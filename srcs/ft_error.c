/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:39:25 by astridgault       #+#    #+#             */
/*   Updated: 2021/06/06 20:01:49 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_basic_error(int argc)
{
	printf("Error\n");
	if (argc < 2)
		printf("There is no mapfile\n");
	else if (argc > 2)
		printf("Wrong number of arguments\n");
	else if (argc == 2)
		printf("This mapfile is not valid\n");
}

void	ft_error_map(int error)
{
	printf("Error\n");
	if (error == 1)
		printf("Invalid map!\n");
	if (error == 2)
		printf("There is more than one player\n");
	if (error == 3)
		printf("There is no player\n");
	if (error == 4)
		printf("There is no collectible\n");
	if (error == 5)
		printf("There is no exit\n");
}