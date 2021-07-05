#include "so_long.h"

/*
void ft_up(t_solong *solong)
{
	int i;
	int j;
	char	*count;

	i = solong->param->pos_x - 1;
	j = solong->param->pos_y;
	if (solong->param->map[i][j] == '1')
		return ;
	solong->param->count++;
	printf("%d\n", solong->param->count);
	if (solong->param->map[i][j] == 'C')
	{
		solong->param->map[i][j] = '0';
		solong->param->c--;
	}
	else if (solong->param->map[i][j] == 'E' && solong->param->c == 0)
	{
		printf ("You did it! GG!");
		solong->param->win = 1;
		ft_close(solong);
	}
	solong->param->pos_x = i;
	solong->param->pos_y = j;
	count = ft_itoa(solong->param->count);
	mlx_string_put(solong->img->mlx, solong->img->win, 10, 10, BLACK, count);
	free(count);
}

void	ft_down(t_solong *solong)
{
	int i;
	int j;
	char *count;

	i = solong->param->pos_x + 1;
	j = solong->param->pos_y;
	if (solong->param->map[i][j] == '1')
		return ;
	solong->param->count++;
	count = ft_itoa(solong->param->count);
	mlx_string_put(solong->img->mlx, solong->img->win, 10, 10, BLACK, count);
	free(count);
	printf("%d\n", solong->param->count);
	if (solong->param->map[i][j] == 'C')
	{
		solong->param->map[i][j] = '0';
		solong->param->c--;
	}
	else if (solong->param->map[i][j] == 'E' && solong->param->c == 0)
	{
		printf ("You did it! GG!");
		solong->param->win = 1;
		ft_close(solong);
	}
	solong->param->pos_x = i;
	solong->param->pos_y = j;
}

void	ft_right(t_solong *solong)
{
	int i;
	int j;
	char *count;

	i = solong->param->pos_x;
	j = solong->param->pos_y + 1;
	if (solong->param->map[i][j] == '1')
		return ;
	solong->param->count++;
	count = ft_itoa(solong->param->count);
	mlx_string_put(solong->img->mlx, solong->img->win, 10, 10, BLACK, count);
	free(count);
	printf("%d\n", solong->param->count);
	if (solong->param->map[i][j] == 'C')
	{
		solong->param->map[i][j] = '0';
		solong->param->c--;
	}
	else if (solong->param->map[i][j] == 'E' && solong->param->c == 0)
	{
		printf ("You did it! GG!");
		solong->param->win = 1;
		ft_close(solong);
	}
	solong->param->pos_x = i;
	solong->param->pos_y = j;
}

void	ft_left(t_solong *solong)
{
	int i;
	int j;
	char *count;

	i = solong->param->pos_x;
	j = solong->param->pos_y - 1;
	if (solong->param->map[i][j] == '1')
		return ;
	solong->param->count++;
	count = ft_itoa(solong->param->count);
	mlx_string_put(solong->img->mlx, solong->img->win, 10, 10, BLACK, count);
	free(count);
	printf("%d\n", solong->param->count);
	if (solong->param->map[i][j] == 'C')
	{
		solong->param->map[i][j] = '0';
		solong->param->c--;
	}
	else if (solong->param->map[i][j] == 'E' && solong->param->c == 0)
	{
		printf ("You did it! GG!\n");
		solong->param->win = 1;
		ft_close(solong);
	}
	solong->param->pos_x = i;
	solong->param->pos_y = j;
}
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long nb;

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


void	ft_actions(t_solong *solong, int i, int j)
{
	char *count;

	if (solong->param->map[i][j] == '1')
		return ;
	solong->param->count++;
	count = ft_itoa(solong->param->count);
	mlx_string_put(solong->img->mlx, solong->img->win, 10, 10, BLACK, count);
	free(count);
	ft_putnbr_fd(solong->param->count, 1); //changertous les printf par ft_putnbr
	write(1, "\r", 1);
	if (solong->param->map[i][j] == 'C')
	{
		solong->param->map[i][j] = '0';
		solong->param->c--;
	}
	else if (solong->param->map[i][j] == 'E' && solong->param->c == 0)
	{
		printf ("You did it! GG!\n");
		solong->param->win = 1;
		ft_close(solong);
	}
	solong->param->pos_x = i;
	solong->param->pos_y = j;
}
