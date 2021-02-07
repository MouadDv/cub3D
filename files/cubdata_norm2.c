/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubdata_norm2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:35:04 by milmi             #+#    #+#             */
/*   Updated: 2021/01/12 09:28:12 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_find(char c, char const *set)
{
	int	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (set[j] == c)
			return (1);
		j++;
	}
	return (0);
}

void	ft_norm(int start, int j, int *len)
{
	if (start > j + 1)
		*len = 1;
	else
		*len = j + 2 - start;
}

void	ft_swaptrim(char *ret, char const *s1, int len, int j)
{
	while (len >= 0)
	{
		ret[len] = s1[j];
		len--;
		j--;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		j;
	int		start;
	int		len;

	if (s1 == NULL || set == NULL)
		return (0);
	j = 0;
	while (ft_find(s1[j], set))
		j++;
	start = j;
	j = ft_strlen(s1) - 1;
	while (j >= 0 && ft_find(s1[j], set) == 1)
		j--;
	ft_norm(start, j, &len);
	if ((ret = ft_calloc(len, sizeof(char))) == NULL)
		return (0);
	len -= 2;
	ft_swaptrim(ret, s1, len, j);
	return (ret);
}

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	if (n == 0)
		return (0);
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && n > i + 1)
		i++;
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}
