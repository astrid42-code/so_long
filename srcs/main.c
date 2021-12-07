/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:28:40 by astridgault       #+#    #+#             */
/*   Updated: 2021/07/30 13:24:38 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkbasic_error(int ac, char **av)
{
	char	*str;
	char	*copy;

	copy = av[1];
	str = NULL;
	if (ac != 2)
	{
		ft_basic_error(ac);
		return (1);
	}
	if (copy)
		str = ft_strchr(copy, '.');
	if (!str)
	{
		ft_basic_error(ac);
		return (1);
	}
	else if (ft_strncmp(str, ".ber", 4) != 0)
	{
		ft_basic_error(ac);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int			fd;
	t_param		param;
	t_sl		sl;
	int			i;

	fd = 0;
	i = 0;
	if (ft_checkbasic_error(ac, av) == 1)
		return (1);
	ft_memset(&param, 0, sizeof(param));
	ft_memset(&sl, 0, sizeof(sl));
	param.file = ft_strdup(av[1]);
	if (ft_read_data(fd, &param) == 1)
	{
		ft_free(&param);
		return (1);
	}
	sl.param = &param;
	ft_start_game(&sl);
	return (0);
}
