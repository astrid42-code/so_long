/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 17:33:33 by astridgault       #+#    #+#             */
/*   Updated: 2021/07/26 12:22:54 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < n - 1)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*copy_s1;

	i = 0;
	copy_s1 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!copy_s1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy_s1[i] = (char)s1[i];
		i++;
	}
	copy_s1[i] = '\0';
	return (copy_s1);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*copy_s;

	i = 0;
	copy_s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!copy_s)
		return (NULL);
	while (s1[i])
	{
		copy_s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		copy_s[i] = s2[j];
		i++;
		j++;
	}
	copy_s[i] = '\0';
	return (copy_s);
}
