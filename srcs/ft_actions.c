/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 13:36:09 by asgaulti          #+#    #+#             */
/*   Updated: 2021/07/29 18:45:14 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10) + 48, fd);
	}
	if (nb <= 9)
		ft_putchar_fd(nb + 48, fd);
}

void	ft_actions(t_sl *sl, int i, int j)
{
	if (sl->param->map[i][j] == '1')
		return ;
	sl->param->count++;
	ft_putnbr_fd(sl->param->count, 1);
	write(1, "\r", 1);
	if (sl->param->map[i][j] == 'C')
	{
		sl->param->map[i][j] = '0';
		sl->param->c--;
	}
	else if (sl->param->map[i][j] == 'E' && sl->param->c == 0)
	{
		write (1, "\nYou did it! GG!\n", 17);
		sl->param->win = 1;
		ft_close(sl);
	}
	sl->param->pos_x = i;
	sl->param->pos_y = j;
}
