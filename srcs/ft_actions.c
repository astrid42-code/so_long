#include "so_long.h"

void ft_up(t_solong *solong)
{
	int i;
	int j;

	i = solong->param->pos_x;
	j = solong->param->pos_y;
printf("char = %d pos-e = %d\n", solong->param->map[i - 1][j], solong->param->pos_e);
		printf("c = %d\n", solong->param->count);

	if (solong->param->map[i - 1][j] == 'E' && solong->param->c == 0) // sf s'il n'a pas tout recolte
	{
		solong->param->count++;
		ft_close(solong);
	}
	else if (solong->param->map[i - 1][j] == 'E' && solong->param->c != 0) // sf s'il n'a pas tout recolte
	{
		solong->param->pos_e = -1;
		solong->param->map[i][j] = '0';
		i--;
		solong->param->pos_x = i;
		solong->param->map[i][j] = 'P';
		ft_minimap(solong);
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
		i--;
		solong->param->pos_x = i;
		solong->param->map[i][j] = 'P';
		if (solong->param->map[i - 1][j] == 'C')
			solong->param->c--;
		ft_minimap(solong);
	}
/*    else if (solong->param->map[i - 1][j] != '1'
		&& solong->param->map[i - 1][j] != 'E'
		&& solong->param->map[i - 1][j] != 'C')
	{
		solong->param->map[i][j] = '0';
		solong->param->pos_x = i;
		i--;
		solong->param->map[i][j] = 'P';
		ft_minimap(solong);
	}
*/	mlx_put_image_to_window(solong->img->mlx, solong->img->win, solong->img->img, 0, 0);
	solong->param->count++;
	printf("%d\n", solong->param->count);
}

void	ft_down(t_solong *solong)
{
	int i;
	int j;

	i = solong->param->pos_x;
	j = solong->param->pos_y;
	printf("char = %d pos-e = %d\n", solong->param->map[i + 1][j], solong->param->pos_e);
		printf("c = %d\n", solong->param->count);
	if (solong->param->map[i + 1][j] == 'E' && solong->param->c == 0) // sf s'il n'a pas tout recolte
	{
		solong->param->count++;
		ft_close(solong);
	}
	else if (solong->param->map[i + 1][j] == 'E' && solong->param->c != 0) // sf s'il n'a pas tout recolte
	{
		solong->param->pos_e = -1;
		solong->param->map[i][j] = '0';
		i++;
		solong->param->pos_x = i;
		solong->param->map[i][j] = 'P';
		ft_minimap(solong);
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
		i++;
		solong->param->pos_x = i;
		solong->param->map[i][j] = 'P';
		if (solong->param->map[i + 1][j] == 'C')
			solong->param->c--;
		ft_minimap(solong);
	}
	mlx_put_image_to_window(solong->img->mlx, solong->img->win, solong->img->img, 0, 0);
	solong->param->count++;
	printf("%d\n", solong->param->count);
}

void	ft_right(t_solong *solong)
{
	int i;
	int j;

	i = solong->param->pos_x;
	j = solong->param->pos_y;
	printf("char = %d pos-e = %d\n", solong->param->map[i][j+1], solong->param->pos_e);
		printf("c = %d\n", solong->param->count);
	if (solong->param->map[i][j + 1] == 'E' && solong->param->c == 0) // sf s'il n'a pas tout recolte
	{
		solong->param->count++;
		ft_close(solong);
	}
	else if (solong->param->map[i][j + 1] == 'E' && solong->param->c != 0) // sf s'il n'a pas tout recolte
	{
		solong->param->pos_e = -1;
		solong->param->map[i][j] = '0';
		j--;
		solong->param->pos_y = j;
		solong->param->map[i][j] = 'P';
		ft_minimap(solong);
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
		j--;
		solong->param->pos_y = j;
		solong->param->map[i][j] = 'P';
		if (solong->param->map[i][j + 1] == 'C')
			solong->param->c--;
		ft_minimap(solong);
	}
	mlx_put_image_to_window(solong->img->mlx, solong->img->win, solong->img->img, 0, 0);
	solong->param->count++;
	printf("%d\n", solong->param->count);
}

void	ft_left(t_solong *solong)
{
	int i;
	int j;

	i = solong->param->pos_x;
	j = solong->param->pos_y;
	printf("char = %d pos-e = %d\n", solong->param->map[i][j-1], solong->param->pos_e);
		printf("c = %d\n", solong->param->count);
	if (solong->param->map[i][j - 1] == 'E' && solong->param->c == 0) // sf s'il n'a pas tout recolte
	{
		solong->param->count++;
		ft_close(solong);
	}
	else if (solong->param->map[i][j - 1] == 'E' && solong->param->c != 0) // sf s'il n'a pas tout recolte
	{
		solong->param->pos_e = -1;
		solong->param->map[i][j] = '0';
		j--;
		solong->param->pos_y = j;
		solong->param->map[i][j] = 'P';
		ft_minimap(solong);
	}
	else if (solong->param->map[i][j - 1] == 'C'
		|| solong->param->map[i][j - 1] == '0')
	{
		if (solong->param->pos_e == -1)
		{
			solong->param->map[i][j] = 'E';
			solong->param->pos_e = 0;
		}
		else
			solong->param->map[i][j] = '0';
		j++;
		solong->param->pos_x = i;
		solong->param->map[i][j] = 'P';
		if (solong->param->map[i][j - 1] == 'C')
			solong->param->c--;
		ft_minimap(solong);
	solong->param->count++;
	printf("%d\n", solong->param->count);
	}
	mlx_put_image_to_window(solong->img->mlx, solong->img->win, solong->img->img, 0, 0);
}
