/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 05:08:41 by milmi             #+#    #+#             */
/*   Updated: 2019/11/22 05:08:44 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		to_free(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (-1);
}

int		verif_reste(char **rest, char **line)
{
	char	*s;
	char	*tmp;

	if (!*rest)
	{
		if ((*rest = ft_strdup("")) == NULL)
			return (0);
	}
	else if ((s = ft_strchr(*rest, '\n')))
	{
		*s = '\0';
		if ((*line = ft_strdup(*rest)) == NULL)
			return (0);
		tmp = *rest;
		if ((*rest = ft_strdup(s + 1)) == NULL)
			return (0);
		to_free(&tmp);
		return (1);
	}
	return (-1);
}

int		ft_read(int fd, char **rest, char **line)
{
	char	*buf;
	int		j;
	char	*s;

	if ((buf = malloc((BUFFER_SIZE + 1) * sizeof(char))) == NULL)
		return (-1);
	while ((j = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[j] = '\0';
		if ((*rest = ft_strjoin(rest, &buf)) == NULL)
			return (-1);
		if ((s = ft_strchr(*rest, '\n')))
		{
			to_free(&buf);
			*s = '\0';
			*line = *rest;
			if ((*rest = ft_strdup(s + 1)) == NULL)
				return (-1);
			return (1);
		}
	}
	to_free(&buf);
	return (j);
}

int		get_next_line(int fd, char **line)
{
	static char	*rest;
	int			j;
	int			k;

	if (fd < 0 || BUFFER_SIZE < 0 || !line)
		return (-1);
	if ((k = verif_reste(&rest, line)) == 0)
		return (-1);
	else if (k == 1)
		return (1);
	j = ft_read(fd, &rest, line);
	if (j == -1)
		return (to_free(&rest));
	if (rest && j == 0)
	{
		if ((*line = ft_strdup(rest)) == NULL)
			return (-1);
		to_free(&rest);
		return (0);
	}
	return (j);
}
