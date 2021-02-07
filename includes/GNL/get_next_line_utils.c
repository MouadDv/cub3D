/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 05:08:57 by milmi             #+#    #+#             */
/*   Updated: 2019/11/22 05:08:59 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, char *src, size_t n)
{
	char	*psrc;
	char	*pdest;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	psrc = (char*)src;
	pdest = (char*)dest;
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(char *s1)
{
	char *dest;

	dest = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s1, (ft_strlen(s1) + 1));
	return (dest);
}

char	*ft_strjoin(char **s1, char **s2)
{
	int		sum;
	char	*newstr;
	char	*str1;
	char	*str2;

	str1 = *s1;
	str2 = *s2;
	if (str1 == NULL || str2 == NULL)
		return (NULL);
	sum = ft_strlen((char *)str1) + ft_strlen((char *)str2);
	newstr = (char *)malloc(sum + 1);
	if (newstr == NULL)
		return (NULL);
	ft_memcpy(newstr, str1, ft_strlen(str1));
	ft_memcpy(newstr + ft_strlen(str1), str2, ft_strlen(str2) + 1);
	free(str1);
	return (newstr);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != c && *s != '\0')
	{
		s++;
	}
	if (*s == c)
	{
		return ((char*)s);
	}
	else
	{
		return (NULL);
	}
}
