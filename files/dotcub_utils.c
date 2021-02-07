/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dotcub_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:56:56 by milmi             #+#    #+#             */
/*   Updated: 2021/01/25 09:13:59 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

long	ft_atoi(const char *str)
{
	long	j;
	long	c;
	long	f;

	j = 0;
	f = 1;
	c = 0;
	while (str[j] == '\r' || str[j] == '\v' || str[j] == '\b'
			|| str[j] == '\f' || str[j] == '\t'
			|| str[j] == '\n' || str[j] == ' ')
		j++;
	if (str[j] == '+' && str[j + 1] != '-')
		j++;
	if (str[j] == '-')
	{
		f = -1;
		j++;
	}
	while (str[j] >= '0' && str[j] <= '9')
	{
		c = c * 10 + str[j] - '0';
		j++;
	}
	return (c * f);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if ((p = malloc(count * size)) == NULL)
		return (0);
	ft_memset(p, '\0', count * size);
	return (p);
}

void	*ft_memset(void *dest, int src, size_t n)
{
	size_t	j;
	char	*p;

	j = 0;
	p = (char *)dest;
	while (j < n)
	{
		p[j] = src;
		j++;
	}
	return (dest);
}

char	*ft_substr_cub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	k;
	size_t	j;

	k = 0;
	j = 0;
	if (s == NULL)
		return (0);
	if (!(ret = (char *)ft_calloc(len + 1, sizeof(char))))
		return (0);
	while (k < start && s[k] != '\0')
		k++;
	if (s[k] == '\0')
		return (ret);
	while (s[k] != '\0' && j < len)
	{
		ret[j] = s[k];
		k++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

float	ft_angle(char c)
{
	if (c == 'N')
		return (PI * 0.5);
	else if (c == 'S')
		return (PI * 1.5);
	else if (c == 'W')
		return (0);
	else if (c == 'E')
		return (PI);
	return (0);
}
