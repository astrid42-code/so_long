/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:28:40 by astridgault       #+#    #+#             */
/*   Updated: 2021/06/09 19:57:59 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	//printf("ac = %d\n", ac);
	//printf("copy = %s\n", copy);
	//printf("str = %s\n", str);
	if (!str)
	{
		//printf("Error\n");
		//printf("This argument is not valid\n");
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

// initialise la struct a 0 (on peut aussi initialiser certaines a ce quon veut en lui precisant)
void	ft_init_struct(t_param *param)
{
	*param = (t_param){0};
}

int		main(int ac, char **av)
{
	int			fd;
	t_param		param;
	int i;

	fd = 0;
	i = 0;
	if (ft_checkbasic_error(ac, av) == 1)
	{
		return (1);
	}
/*	else // a retirer car doublon avec parse_map?
	{
		//printf("file = %s\n", av[1]);
		fd = open(av[1], O_RDONLY);
		//printf("fd = %d\n", fd);
		if (fd < 0)
		{
			printf("Error\n");
			printf("No file\n");
			return (1);
		}
	}
*/	ft_init_struct(&param);
	//printf("map = %s\n", param.map[i]);
	param.file = ft_strdup(av[1]);
	if (ft_read_data(fd, &param) == 1)
	{
		if (param.map)
			ft_free_map(&param);
	
		if (param.file)
			free(param.file);
		return (1);
	}
	//ft_start_game(&param); //ou if ft_start_game == 0 pour le return error?
	//ft_free_param(&param); // a mettre dans la fct exit finale (free les params, la minilibx, ...)
	ft_free_map(&param);
	if (param.file)
		free(param.file);
	puts("GG");
	return (0);
}
