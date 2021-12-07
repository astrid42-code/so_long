/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:21:20 by asgaulti          #+#    #+#             */
/*   Updated: 2021/07/30 13:24:37 by asgaulti@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*copy_s;

	i = 0;
	j = 0;
	copy_s = malloc(sizeof(char) * (len + 1));
	if (!copy_s)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			copy_s[j++] = s[i];
		i++;
	}
	copy_s[j] = '\0';
	return (copy_s);
}

void	ft_memset(void *data, int c, size_t len)
{
	while (len--)
		*(char *)data++ = c;
}

static int	ft_len(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*tab;

	nb = n;
	len = ft_len(n);
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	tab[len--] = '\0';
	if (nb == 0)
		tab[0] = 48;
	if (nb < 0)
	{
		tab[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		tab[len] = (nb % 10) + 48;
		nb /= 10;
		len--;
	}
	return (tab);
}
