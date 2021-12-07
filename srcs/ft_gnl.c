/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:57:10 by astridgault       #+#    #+#             */
/*   Updated: 2021/07/30 12:48:02 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_get_static(char *str, char buf[BUF_SIZE], int len)
{
	char	*tmp;

	buf[len] = '\0';
	if (!str)
		str = ft_strdup(buf);
	else if (str)
	{
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	return (str);
}

char	*ft_stock_line(char *str, char **line)
{
	size_t	i;
	size_t	len;
	char	*tmp;

	i = 0;
	len = ft_strlen(str);
	while (str[i] != '\n' && str[i])
		i++;
	if (i < len)
	{
		*line = ft_substr(str, 0, i);
		tmp = str;
		str = ft_substr(str, i + 1, len);
		free(tmp);
	}
	else
	{
		*line = str;
		str = NULL;
	}
	return (str);
}

// pb de norne avec assignation de len dans le while
int	get_next_line(int fd, char **line)
{
	int				len;
	char			buf[BUF_SIZE + 1];
	static char		*str;

	if (fd < 0 || !line || BUF_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	len = read(fd, buf, BUF_SIZE);
	while (len > 0)
	{
		str = ft_get_static(str, buf, len);
		if (ft_strchr(str, '\n'))
			break ;
		len = read(fd, buf, BUF_SIZE);
	}
	if (!str)
	{
		*line = ft_strdup("");
		return (0);
	}
	str = ft_stock_line(str, line);
	if (!str)
		return (0);
	return (1);
}

char	**ft_get_file(int fd, int lvl)
{
	char	*line;
	char	**tab;

	line = NULL;
	if (get_next_line(fd, &line) == 1)
		tab = ft_get_file(fd, lvl + 1);
	else
	{
		tab = malloc(sizeof(char *) * (lvl + 2));
		tab[lvl + 1] = NULL;
	}
	tab[lvl] = line;
	return (tab);
}
