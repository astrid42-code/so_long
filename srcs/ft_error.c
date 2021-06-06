/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:39:25 by astridgault       #+#    #+#             */
/*   Updated: 2021/06/06 17:52:42 by astridgault      ###   ########.fr       */
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