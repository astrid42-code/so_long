#include "so_long.h"

void ft_up(t_solong *solong)
{
	int i;
	int j;

	i = solong->param->pos_x - 1;
	j = solong->param->pos_y;
	if (solong->param->map[i][j] == '1')
		return ;
	if (solong->param->map[i][j] == 'C')
	{
		solong->param->map[i][j] = '0';
		solong->param->c--;
	}
	else if (solong->param->map[i][j] == 'E' && solong->param->c == 0)
	{
		printf ("You did it! GG!");
		//solong->param->win = 1;
		ft_win(solong);
		// compteur++ ici aussi?
	}
	solong->param->count++;
	solong->param->pos_x = i;
	solong->param->pos_y = j;
/*
	i = solong->param->pos_x;
	j = solong->param->pos_y;
	if (solong->param->map[i - 1][j] == 'E' && solong->param->c == 0) // sf s'il n'a pas tout recolte
	{
		solong->param->count++;
		solong->param->map[i][j] = '0';
		i--;
		solong->param->pos_x = i;
		solong->param->map[i][j] = 'P';
		printf ("You did it! GG!");
		ft_win(solong);
	}
	else if (solong->param->map[i - 1][j] == 'E' && solong->param->c != 0) // sf s'il n'a pas tout recolte
	{
		solong->param->pos_e = -1;
		solong->param->map[i][j] = '0';
		i--;
		solong->param->pos_x = i;
		solong->param->map[i][j] = 'P';
		solong->param->count++;
	}
	else if (solong->param->map[i - 1][j] == 'C'
		|| solong->param->map[i - 1][j] == '0')
	{
		if (solong->param->pos_e == -1)
		{
			solong->param->map[i][j] = 'E';
			solong->param->pos_e = 0;
		}
		else
			solong->param->map[i][j] = '0';
		if (solong->param->map[i - 1][j] == 'C')
			solong->param->c--;
		i--;
		solong->param->pos_x = i;
		solong->param->map[i][j] = 'P';
		solong->param->count++;
	}
	mlx_put_image_to_window(solong->img->mlx, solong->img->win, solong->img->img, 0, 0);
	printf("%d\n", solong->param->count);
	*/
}

void	ft_down(t_solong *solong)
{
	int i;
	int j;

	i = solong->param->pos_x + 1;
	j = solong->param->pos_y;
	if (solong->param->map[i][j] == '1')
		return ;
	if (solong->param->map[i][j] == 'C')
	{
		solong->param->map[i][j] = '0';
		solong->param->c--;
	}
	else if (solong->param->map[i][j] == 'E' && solong->param->c == 0)
	{
		printf ("You did it! GG!");
		//solong->param->win = 1;
		ft_win(solong);
	}
	solong->param->count++;
	solong->param->pos_x = i;
	solong->param->pos_y = j;
/*
	i = solong->param->pos_x;
	j = solong->param->pos_y;
	if (solong->param->map[i + 1][j] == 'E' && solong->param->c == 0) // sf s'il n'a pas tout recolte
	{
		solong->param->count++;
		solong->param->map[i][j] = '0';
		i++;
		solong->param->pos_x = i;
		solong->param->map[i][j] = 'P';
		printf ("You did it! GG!");
		//ft_close(solong);
	}
	else if (solong->param->map[i + 1][j] == 'E' && solong->param->c != 0) // sf s'il n'a pas tout recolte
	{
		solong->param->pos_e = -1;
		solong->param->map[i][j] = '0';
		i++;
		solong->param->pos_x = i;
		solong->param->map[i][j] = 'P';
		solong->param->count++;
	}
	else if (solong->param->map[i + 1][j] == 'C'
		|| solong->param->map[i + 1][j] == '0')
	{
		if (solong->param->pos_e == -1)
		{
			solong->param->map[i][j] = 'E';
			solong->param->pos_e = 0;
		}
		else
			solong->param->map[i][j] = '0';
		if (solong->param->map[i + 1][j] == 'C')
			solong->param->c--;
		i++;
		solong->param->pos_x = i;
		solong->param->map[i][j] = 'P';
		solong->param->count++;
	}
	mlx_put_image_to_window(solong->img->mlx, solong->img->win, solong->img->img, 0, 0);
	printf("%d\n", solong->param->count);
	*/
}

void	ft_right(t_solong *solong)
{
	int i;
	int j;

	i = solong->param->pos_x;
	j = solong->param->pos_y + 1;
	if (solong->param->map[i][j] == '1')
		return ;
	if (solong->param->map[i][j] == 'C')
	{
		solong->param->map[i][j] = '0';
		solong->param->c--;
	}
	else if (solong->param->map[i][j] == 'E' && solong->param->c == 0)
	{
		printf ("You did it! GG!");
		//solong->param->win = 1;
		ft_win(solong);
	}
	solong->param->count++;
	solong->param->pos_x = i;
	solong->param->pos_y = j;
	/*
	i = solong->param->pos_x;
	j = solong->param->pos_y;
	printf("char = %c pos-e = %d\n", solong->param->map[i][j+1], solong->param->pos_e);
	if (solong->param->map[i][j + 1] == 'E' && solong->param->c == 0) // sf s'il n'a pas tout recolte
	{
		solong->param->count++;
		solong->param->map[i][j] = '0';
		j++;
		solong->param->pos_y = j;
		solong->param->map[i][j] = 'P';
		printf ("You did it! GG!");
	}
	else if (solong->param->map[i][j + 1] == 'E' && solong->param->c != 0) // sf s'il n'a pas tout recolte
	{
		solong->param->pos_e = -1;
		solong->param->map[i][j] = '0';
		j++;
		solong->param->pos_y = j;
		solong->param->map[i][j] = 'P';
		solong->param->count++;
	}
	else if (solong->param->map[i][j + 1] == 'C'
		|| solong->param->map[i][j + 1] == '0')
	{
		if (solong->param->pos_e == -1)
		{
			solong->param->map[i][j] = 'E';
			solong->param->pos_e = 0;
		}
		else
			solong->param->map[i][j] = '0';
		if (solong->param->map[i][j + 1] == 'C')
			solong->param->c--;
		j++;
		solong->param->pos_y = j;
		solong->param->map[i][j] = 'P';
		solong->param->count++;
	}
	mlx_put_image_to_window(solong->img->mlx, solong->img->win, solong->img->img, 0, 0);
	printf("%d\n", solong->param->count);
	*/
}

void	ft_left(t_solong *solong)
{
	int i;
	int j;

	i = solong->param->pos_x;
	j = solong->param->pos_y - 1;
	if (solong->param->map[i][j] == '1')
		return ;
	if (solong->param->map[i][j] == 'C')
	{
		solong->param->map[i][j] = '0';
		solong->param->c--;
	}
	else if (solong->param->map[i][j] == 'E' && solong->param->c == 0)
	{
		printf ("You did it! GG!\n");
		//solong->param->win = 1;
		ft_win(solong);
	}
	solong->param->count++;
	solong->param->pos_x = i;
	solong->param->pos_y = j;
/*
	if (solong->param->map[i][j - 1] == 'E' && solong->param->c == 0) // sf s'il n'a pas tout recolte
	{
		solong->param->count++;
		//solong->param->map[i][j] = '0';
		j--;
		solong->param->pos_y = j;
		//solong->param->map[i][j] = 'P';
		printf ("You did it! GG!");
	}
	else if (solong->param->map[i][j - 1] == 'E' && solong->param->c != 0) // sf s'il n'a pas tout recolte
	{
		solong->param->pos_e = -1;
		//solong->param->map[i][j] = '0';
		j--;
		solong->param->pos_y = j;
		//solong->param->map[i][j] = 'P';
		solong->param->count++;
	}
	else if (solong->param->map[i][j - 1] == 'C'
		|| solong->param->map[i][j - 1] == '0')
	{
		if (solong->param->pos_e == -1)
		{
			//solong->param->map[i][j] = 'E';
			solong->param->pos_e = 0;
		}
		else
			solong->param->map[i][j] = '0';
		if (solong->param->map[i][j - 1] == 'C')
			solong->param->c--;
		j--;
		solong->param->pos_x = i;
		//solong->param->map[i][j] = 'P';
		solong->param->count++;
	}
	mlx_put_image_to_window(solong->img->mlx, solong->img->win, solong->img->img, 0, 0);
	printf("%d\n", solong->param->count);
	*/
}
