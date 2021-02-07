/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubdata_norm4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:42:11 by milmi             #+#    #+#             */
/*   Updated: 2021/01/25 08:52:02 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checkeatexture(char *str)
{
	int i;

	i = 3;
	if (str[0] == 'E' && str[1] == 'A' &&
		str[2] == ' ' && g_cubedata.easttexture == NULL)
	{
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		g_cubedata.easttexture = ft_substr_cub(str, i, ft_strlen(str + i));
		if (!g_cubedata.easttexture)
			return (-6);
		add_to_list(g_cubedata.easttexture);
		if (checkextenxion(str) == 0)
			return (-6);
		return (1);
	}
	return (-2);
}

int	checksotexture(char *str)
{
	int i;

	i = 3;
	if (str[0] == 'S' && str[1] == 'O' &&
		str[2] == ' ' && g_cubedata.southtexture == NULL)
	{
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		g_cubedata.southtexture = ft_substr_cub(str, i, ft_strlen(str + i));
		if (!g_cubedata.southtexture)
			return (-7);
		add_to_list(g_cubedata.southtexture);
		if (checkextenxion(str) == 0)
			return (-7);
		return (1);
	}
	return (-2);
}

int	checksptexture(char *str)
{
	int i;

	i = 2;
	if (str[0] == 'S' && str[1] == ' ' && g_cubedata.spritetexture == NULL)
	{
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		g_cubedata.spritetexture = ft_substr_cub(str, i, ft_strlen(str + i));
		if (!g_cubedata.spritetexture)
			return (-8);
		add_to_list(g_cubedata.spritetexture);
		if (checkextenxion(str) == 0)
			return (-8);
		return (1);
	}
	return (-2);
}

int	checkfloor_norm(char *str, int *i)
{
	while (str[*i] != '\0' && str[*i] == ' ')
		*i = *i + 1;
	if (str[*i] >= '0' && str[*i] <= '9')
		g_colornorm.red = ft_atoi(str + *i);
	else
		return (-9);
	if (g_colornorm.red < 0 || g_colornorm.red > 255)
		return (-9);
	while (str[*i] != '\0' && (str[*i] >= '0' && str[*i] <= '9'))
		*i = *i + 1;
	while (str[*i] != '\0' && str[*i] == ' ')
		*i = *i + 1;
	if (str[*i] != ',')
		return (-9);
	*i = *i + 1;
	while (str[*i] != '\0' && str[*i] == ' ')
		*i = *i + 1;
	g_colornorm.green = ft_atoi(str + *i);
	if (g_colornorm.green < 0 || g_colornorm.green > 255)
		return (-9);
	while (str[*i] != '\0' && (str[*i] >= '0' && str[*i] <= '9'))
		*i = *i + 1;
	while (str[*i] != '\0' && str[*i] == ' ')
		*i = *i + 1;
	return (1);
}

int	checkfloor(char *str)
{
	int	i;
	int	ret;

	i = 2;
	if (str[0] == 'F' && str[1] == ' ' && g_cubedata.floorcolor == -1)
	{
		if ((ret = checkfloor_norm(str, &i)) < 0)
			return (ret);
		if (str[i] != ',' || str[i + 1] == '\0')
			return (-9);
		i++;
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		g_colornorm.blue = ft_atoi(str + i);
		if (g_colornorm.blue < 0 || g_colornorm.blue > 255)
			return (-9);
		while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
			i++;
		if (str[i] == '\0')
			return ((g_cubedata.floorcolor = (g_colornorm.red << 16)
		+ (g_colornorm.green << 8) + g_colornorm.blue));
			return (-9);
	}
	return (-2);
}
